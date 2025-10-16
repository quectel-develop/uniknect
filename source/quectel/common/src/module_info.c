#include "qosa_def.h"
#include "qosa_log.h"
#include "module_info.h"

static Module_Type s_module = MOD_TYPE_DEFAULT;
static char s_module_name[64] = "UNKNOWN";
static const module_type_map_t s_module_type_map[] = {
    {"BG95",    MOD_TYPE_BG95},
    {"BG96",    MOD_TYPE_BG96},
    {"BG770",	MOD_TYPE_BG770},
    {"EC800M",  MOD_TYPE_EC800M},
    {"EC25",    MOD_TYPE_EC25}
    // Can be further expanded...
};

bool set_module_type(const char* type)
{
    int i = 0;
    if (NULL == type)
        return QOSA_FALSE;
    for (i = 0; i < sizeof(s_module_type_map) / sizeof(module_type_map_t); i++)
    {
        if (strstr(type, s_module_type_map[i].name) != NULL)
        {
            s_module = s_module_type_map[i].type;
            strcpy(s_module_name, type);
            s_module_name[strlen(s_module_name) - 1] = '\0'; // delete \r\n
            LOG_I("module = %s type = %d", s_module_name, s_module);
            return QOSA_TRUE;
        }
    }
    return QOSA_FALSE;
}

Module_Type get_module_type()
{
    return s_module;
}

const char* get_module_type_name()
{
    return s_module_name;
}
