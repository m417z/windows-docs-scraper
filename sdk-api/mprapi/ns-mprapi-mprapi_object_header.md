# MPRAPI_OBJECT_HEADER structure

## Description

The [RAS_UPDATE_CONNECTION](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_update_connection), [AUTH_VALIDATION_EX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-auth_validation_ex) structures, and the structure version used by the [MprAdminConnectionEnumEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionenumex) method.

## Members

### `revision`

A value that represents the version of the structure specified by **type**. Possible values are:

| Value | Meaning |
| --- | --- |
| **MPRAPI_RAS_CONNECTION_OBJECT_REVISION_1**<br><br>0x01 | Represents version 1 of the [RAS_CONNECTION_EX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_ex) structure if **type** is **MPRAPI_OBJECT_TYPE_RAS_CONNECTION_OBJECT**. |
| **MPRAPI_MPR_SERVER_OBJECT_REVISION_1**<br><br>0x01 | Represents version 1 of the [MPR_SERVER_EX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_ex0) structure if **type** is **MPRAPI_OBJECT_TYPE_MPR_SERVER_OBJECT**. |
| **MPRAPI_MPR_SERVER_SET_CONFIG_OBJECT_REVISION_1**<br><br>0x01 | Represents version 1 of the [MPR_SERVER_SET_CONFIG_EX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_set_config_ex0) structure if **type** is **MPRAPI_OBJECT_TYPE_MPR_SERVER_SET_CONFIG_OBJECT**. |

#### type

A value from the [MPRAPI_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-mprapi_object_type) enumeration that specifies the structure type.

#### size

The size, in bytes, of the structure based on **type** and **revision**.

### `type`

### `size`

## See also

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Router Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/router-management-structures)