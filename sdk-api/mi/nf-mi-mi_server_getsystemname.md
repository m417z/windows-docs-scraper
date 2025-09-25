# MI_Server_GetSystemName function

## Description

Gets the system name for the server.

## Parameters

### `systemName`

Returned system name.

## Return value

This function returns MI_Result MI_CALL.

## Remarks

This function is only available from within a generated provider. It obtains the system name for this server. The system name is used in several standard CIM key properties (for example, CIM_Fan.SystemName). The name is only known by the server. The provider should use only this function to get the system name and should never attempt to determine the system name using other means. The system name is typically the host name for the system, but the server may add additional qualification.