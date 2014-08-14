/*
** Copyright (C) 2014 Cisco and/or its affiliates. All rights reserved.
 * Copyright (C) 2002-2013 Sourcefire, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License Version 2 as
 * published by the Free Software Foundation.  You may not use, modify or
 * distribute this program under any other version of the GNU General
 * Public License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
// config_deleted.cc author Josh Rosenbaum <jrosenba@cisco.com>

#include <sstream>
#include <vector>

#include "conversion_state.h"
#include "utils/converter.h"
#include "utils/snort2lua_util.h"

namespace config
{

namespace {


class Deleted : public ConversionState
{
public:
    Deleted(Converter* cv, LuaData* ld) : ConversionState(cv, ld) {};
    virtual ~Deleted() {};
    virtual bool convert(std::istringstream& data_stream);
};

} // namespace


bool Deleted::convert(std::istringstream& data_stream)
{
    data_stream.setstate(std::ios::eofbit); // deleted, not failures
    return true;
}

template<const std::string *snort_option>
static ConversionState* deleted_ctor(Converter* cv, LuaData* ld)
{
    // set here since not all delted configs have options
    if (!ld->is_quiet_mode())
    {
        ld->open_table("deleted_snort_config_options");
        ld->add_deleted_comment("config " + *snort_option + "[:.*]");
        ld->close_table();
    }

    return new Deleted(cv, ld);
}

/*************************************************
 ********************  cs_dir  *******************
 *************************************************/

static const std::string cs_dir = "cs_dir";
static const ConvertMap cs_dir_api =
{
    cs_dir,
    deleted_ctor<&cs_dir>,
};

const ConvertMap* cs_dir_map = &cs_dir_api;

/*************************************************
 *******  disable-attribute-reload-thread  *******
 *************************************************/

static const std::string disable_attribute_reload_thread = "disable-attribute-reload-thread";
static const ConvertMap disable_attribute_reload_thread_api =
{
    disable_attribute_reload_thread,
    deleted_ctor<&disable_attribute_reload_thread>,
};

const ConvertMap* disable_attribute_reload_thread_map = &disable_attribute_reload_thread_api;

/*************************************************
 ************  disable_decode_alerts  ************
 *************************************************/

static const std::string disable_decode_alerts = "disable_decode_alerts";
static const ConvertMap disable_decode_alerts_api =
{
    disable_decode_alerts,
    deleted_ctor<&disable_decode_alerts>,
};

const ConvertMap* disable_decode_alerts_map = &disable_decode_alerts_api;

/*************************************************
 *************  disable_decode_drops *************
 *************************************************/

static const std::string disable_decode_drops = "disable_decode_drops";
static const ConvertMap disable_decode_drops_api =
{
    disable_decode_drops,
    deleted_ctor<&disable_decode_drops>,
};

const ConvertMap* disable_decode_drops_map = &disable_decode_drops_api;

/*************************************************
 *************  disable_ipopt_alerts  ************
 *************************************************/

static const std::string disable_ipopt_alerts = "disable_ipopt_alerts";
static const ConvertMap disable_ipopt_alerts_api =
{
    disable_ipopt_alerts,
    deleted_ctor<&disable_ipopt_alerts>,
};

const ConvertMap* disable_ipopt_alerts_map = &disable_ipopt_alerts_api;

/*************************************************
 *************  disable_ipopt_drops  *************
 *************************************************/

static const std::string disable_ipopt_drops = "disable_ipopt_drops";
static const ConvertMap disable_ipopt_drops_api =
{
    disable_ipopt_drops,
    deleted_ctor<&disable_ipopt_drops>,
};

const ConvertMap* disable_ipopt_drops_map = &disable_ipopt_drops_api;

/*************************************************
 ************  disable_tcpopt_alerts  ************
 *************************************************/

static const std::string disable_tcpopt_alerts = "disable_tcpopt_alerts";
static const ConvertMap disable_tcpopt_alerts_api =
{
    disable_tcpopt_alerts,
    deleted_ctor<&disable_tcpopt_alerts>,
};

const ConvertMap* disable_tcpopt_alerts_map = &disable_tcpopt_alerts_api;

/*************************************************
 *************  disable_tcpopt_drops  ************
 *************************************************/

static const std::string disable_tcpopt_drops = "disable_tcpopt_drops";
static const ConvertMap disable_tcpopt_drops_api =
{
    disable_tcpopt_drops,
    deleted_ctor<&disable_tcpopt_drops>,
};

const ConvertMap* disable_tcpopt_drops_map = &disable_tcpopt_drops_api;

/*************************************************
 ******  disable_tcpopt_experimental_alerts  *****
 *************************************************/

static const std::string disable_tcpopt_experimental_alerts = "disable_tcpopt_experimental_alerts";
static const ConvertMap disable_tcpopt_experimental_alerts_api =
{
    disable_tcpopt_experimental_alerts,
    deleted_ctor<&disable_tcpopt_experimental_alerts>,
};

const ConvertMap* disable_tcpopt_experimental_alerts_map = &disable_tcpopt_experimental_alerts_api;

/*************************************************
 *******  disable_tcpopt_experimental_drops ******
 *************************************************/

static const std::string disable_tcpopt_experimental_drops = "disable_tcpopt_experimental_drops";
static const ConvertMap disable_tcpopt_experimental_drops_api =
{
    disable_tcpopt_experimental_drops,
    deleted_ctor<&disable_tcpopt_experimental_drops>,
};

const ConvertMap* disable_tcpopt_experimental_drops_map = &disable_tcpopt_experimental_drops_api;

/*************************************************
 ********  disable_tcpopt_obsolete_alerts  *******
 *************************************************/

static const std::string disable_tcpopt_obsolete_alerts = "disable_tcpopt_obsolete_alerts";
static const ConvertMap disable_tcpopt_obsolete_alerts_api =
{
    disable_tcpopt_obsolete_alerts,
    deleted_ctor<&disable_tcpopt_obsolete_alerts>,
};

const ConvertMap* disable_tcpopt_obsolete_alerts_map = &disable_tcpopt_obsolete_alerts_api;

/*************************************************
 *********  disable_tcpopt_obsolete_drops  ********
 *************************************************/

static const std::string disable_tcpopt_obsolete_drops = "disable_tcpopt_obsolete_drops";
static const ConvertMap disable_tcpopt_obsolete_drops_api =
{
    disable_tcpopt_obsolete_drops,
    deleted_ctor<&disable_tcpopt_obsolete_drops>,
};

const ConvertMap* disable_tcpopt_obsolete_drops_map = &disable_tcpopt_obsolete_drops_api;

/*************************************************
 **********  disable_tcpopt_ttcp_alerts  **********
 *************************************************/

static const std::string disable_tcpopt_ttcp_alerts = "disable_tcpopt_ttcp_alerts";
static const ConvertMap disable_tcpopt_ttcp_alerts_api =
{
    disable_tcpopt_ttcp_alerts,
    deleted_ctor<&disable_tcpopt_ttcp_alerts>,
};

const ConvertMap* disable_tcpopt_ttcp_alerts_map = &disable_tcpopt_ttcp_alerts_api;

/*************************************************
 **************  disable_ttcp_drops  **************
 *************************************************/

static const std::string disable_ttcp_drops = "disable_ttcp_drops";
static const ConvertMap disable_ttcp_drops_api =
{
    disable_ttcp_drops,
    deleted_ctor<&disable_ttcp_drops>,
};

const ConvertMap* disable_ttcp_drops_map = &disable_ttcp_drops_api;

/*************************************************
 ************  dump-dynamic-rules-path  ***********
 *************************************************/

static const std::string dump_dynamic_rules_path = "dump-dynamic-rules-path";
static const ConvertMap dump_dynamic_rules_path_api =
{
    dump_dynamic_rules_path,
    deleted_ctor<&dump_dynamic_rules_path>,
};

const ConvertMap* dump_dynamic_rules_path_map = &dump_dynamic_rules_path_api;

/*************************************************
 *************  enable_decode_drops  *************
 *************************************************/

static const std::string enable_decode_drops = "enable_decode_drops";
static const ConvertMap enable_decode_drops_api =
{
    enable_decode_drops,
    deleted_ctor<&enable_decode_drops>,
};

const ConvertMap* enable_decode_drops_map = &enable_decode_drops_api;

/*************************************************
 *************  disable_ttcp_alerts  *************
 *************************************************/

static const std::string disable_ttcp_alerts = "disable_ttcp_alerts";
static const ConvertMap disable_ttcp_alerts_api =
{
    disable_ttcp_alerts,
    deleted_ctor<&disable_ttcp_alerts>,
};

const ConvertMap* disable_ttcp_alerts_map = &disable_ttcp_alerts_api;

/*************************************************
 ********  enable_decode_oversized_alerts  *******
 *************************************************/

static const std::string enable_decode_oversized_alerts = "enable_decode_oversized_alerts";
static const ConvertMap enable_decode_oversized_alerts_api =
{
    enable_decode_oversized_alerts,
    deleted_ctor<&enable_decode_oversized_alerts>,
};

const ConvertMap* enable_decode_oversized_alerts_map = &enable_decode_oversized_alerts_api;


/*************************************************
 ********  enable_decode_oversized_drops  ********
 *************************************************/

static const std::string enable_decode_oversized_drops = "enable_decode_oversized_drops";
static const ConvertMap enable_decode_oversized_drops_api =
{
    enable_decode_oversized_drops,
    deleted_ctor<&enable_decode_oversized_drops>,
};

const ConvertMap* enable_decode_oversized_drops_map = &enable_decode_oversized_drops_api;

/*************************************************
 **************  enable_ipopt_drops  *************
 *************************************************/

static const std::string enable_ipopt_drops = "enable_ipopt_drops";
static const ConvertMap enable_ipopt_drops_api =
{
    enable_ipopt_drops,
    deleted_ctor<&enable_ipopt_drops>,
};

const ConvertMap* enable_ipopt_drops_map = &enable_ipopt_drops_api;

/*************************************************
 *************  enable_tcpopt_drops  *************
 *************************************************/

static const std::string enable_tcpopt_drops = "enable_tcpopt_drops";
static const ConvertMap enable_tcpopt_drops_api =
{
    enable_tcpopt_drops,
    deleted_ctor<&enable_tcpopt_drops>,
};

const ConvertMap* enable_tcpopt_drops_map = &enable_tcpopt_drops_api;

/*************************************************
 *******  enable_tcpopt_experimental_drops  ******
 *************************************************/

static const std::string enable_tcpopt_experimental_drops = "enable_tcpopt_experimental_drops";
static const ConvertMap enable_tcpopt_experimental_drops_api =
{
    enable_tcpopt_experimental_drops,
    deleted_ctor<&enable_tcpopt_experimental_drops>,
};

const ConvertMap* enable_tcpopt_experimental_drops_map = &enable_tcpopt_experimental_drops_api;

/*************************************************
 *********  enable_tcpopt_obsolete_drops  ********
 *************************************************/

static const std::string enable_tcpopt_obsolete_drops = "enable_tcpopt_obsolete_drops";
static const ConvertMap enable_tcpopt_obsolete_drops_api =
{
    enable_tcpopt_obsolete_drops,
    deleted_ctor<&enable_tcpopt_obsolete_drops>,
};

const ConvertMap* enable_tcpopt_obsolete_drops_map = &enable_tcpopt_obsolete_drops_api;

/*************************************************
 ***********  enable_tcpopt_ttcp_drops  ***********
 *************************************************/

static const std::string enable_tcpopt_ttcp_drops = "enable_tcpopt_ttcp_drops";
static const ConvertMap enable_tcpopt_ttcp_drops_api =
{
    enable_tcpopt_ttcp_drops,
    deleted_ctor<&enable_tcpopt_ttcp_drops>,
};

const ConvertMap* enable_tcpopt_ttcp_drops_map = &enable_tcpopt_ttcp_drops_api;

/*************************************************
 ***********  enable_ttcp_drops  ***********
 *************************************************/

static const std::string enable_ttcp_drops = "enable_ttcp_drops";
static const ConvertMap enable_ttcp_drops_api =
{
    enable_ttcp_drops,
    deleted_ctor<&enable_ttcp_drops>,
};

const ConvertMap* enable_ttcp_drops_map = &enable_ttcp_drops_api;

/*************************************************
 **************  flexresp2_attempts  *************
 *************************************************/

static const std::string flexresp2_attempts = "flexresp2_attempts";
static const ConvertMap flexresp2_attempts_api =
{
    flexresp2_attempts,
    deleted_ctor<&flexresp2_attempts>,
};

const ConvertMap* flexresp2_attempts_map = &flexresp2_attempts_api;

/*************************************************
 *************  flexresp2_interface  *************
 *************************************************/

static const std::string flexresp2_interface = "flexresp2_interface";
static const ConvertMap flexresp2_interface_api =
{
    flexresp2_interface,
    deleted_ctor<&flexresp2_interface>,
};
const ConvertMap* flexresp2_interface_map = &flexresp2_interface_api;

/*************************************************
 ***************  flexresp2_memcap  **************
 *************************************************/


static const std::string flexresp2_memcap = "flexresp2_memcap";
static const ConvertMap flexresp2_memcap_api =
{
    flexresp2_memcap,
    deleted_ctor<&flexresp2_memcap>,
};
const ConvertMap* flexresp2_memcap_map = &flexresp2_memcap_api;

/*************************************************
 ****************  flexresp2_rows  ***************
 *************************************************/

static const std::string flexresp2_rows = "flexresp2_rows";
static const ConvertMap flexresp2_rows_api =
{
    flexresp2_rows,
    deleted_ctor<&flexresp2_rows>,
};
const ConvertMap* flexresp2_rows_map = &flexresp2_rows_api;

/*************************************************
 ************  include_vlan_in_alerts  ***********
 *************************************************/

static const std::string include_vlan_in_alerts = "include_vlan_in_alerts";
static const ConvertMap include_vlan_in_alerts_api =
{
    include_vlan_in_alerts,
    deleted_ctor<&include_vlan_in_alerts>,
};
const ConvertMap* include_vlan_in_alerts_map = &include_vlan_in_alerts_api;

/*************************************************
 ******************  interface  ******************
 *************************************************/

static const std::string interface = "interface";
static const ConvertMap interface_api =
{
    interface,
    deleted_ctor<&interface>,
};
const ConvertMap* interface_map = &interface_api;

/*************************************************
 *****************  layer2resets  ****************
 *************************************************/

static const std::string layer2resets = "layer2resets";
static const ConvertMap layer2resets_api =
{
    layer2resets,
    deleted_ctor<&layer2resets>,
};
const ConvertMap* layer2resets_map = &layer2resets_api;

/*************************************************
 ****************  policy_version  ***************
 *************************************************/

static const std::string policy_version = "policy_version";
static const ConvertMap policy_version_api =
{
    policy_version,
    deleted_ctor<&policy_version>,
};
const ConvertMap* policy_version_map = &policy_version_api;

/*************************************************
 ****************  so_rule_memcap  ***************
 *************************************************/

static const std::string so_rule_memcap = "so_rule_memcap";
static const ConvertMap so_rule_memcap_api =
{
    so_rule_memcap,
    deleted_ctor<&so_rule_memcap>,
};
const ConvertMap* so_rule_memcap_map = &so_rule_memcap_api;

} // namespace config