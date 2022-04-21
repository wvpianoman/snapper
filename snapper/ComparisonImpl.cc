/*
 * Copyright (c) 2022 SUSE LLC
 *
 * All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, contact Novell, Inc.
 *
 * To contact Novell about this file by physical or electronic mail, you may
 * find current contact information at www.novell.com.
 */


#include <dirent.h>
#include <regex>

#include "snapper/SnapperTmpl.h"


namespace snapper
{

    using std::string;
    using std::regex;


    string
    filelist_name(unsigned int num)
    {
	return "filelist-" + decString(num) + ".txt";
    }


    bool
    is_filelist_file(unsigned char type, const char* name)
    {
	static const regex rx("filelist-([0-9]+).txt(\\.gz)?", regex::extended);

	if (type != DT_UNKNOWN && type != DT_REG)
	    return false;

	return regex_match(name, rx);
    }

}
