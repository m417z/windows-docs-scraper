# PSTART_COMPLETE callback function

## Description

Router Manager calls the
**StartComplete** function to inform the routing protocol that initialization is complete and all interfaces have been added. The routing protocol should wait for this call before starting any protocol-specific behavior.

The [PSTART_COMPLETE](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-mpr50_routing_characteristics) type defines a pointer to this callback function. *StartComplete* is a placeholder for the application-defined function name.

## Parameters

### `unnamedParam1`

## Return value

This function should return NO_ERROR.

## See also

[StartProtocol](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pstart_protocol)