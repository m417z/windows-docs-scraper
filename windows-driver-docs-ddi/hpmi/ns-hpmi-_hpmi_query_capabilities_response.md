# _HPMI_QUERY_CAPABILITIES_RESPONSE structure

## Description

HPMI_QUERY_CAPABILITIES_RESPONSE is a structure used to return information about software defined batteries (SDB).

## Members

### `Version`

Set to HPMI_QUERY_CAPABILITIES_VERSION_1.

### `RequestService`

Requests one or more Windows services as defined by
HPMI_REQUEST_SERVICE_XXX.

### `SdbCapabilities`

Specifies Software Defined Battery (SDB) features supported by the system.

 This field is set to combination of one or more HPMI_CAPABILITY_SDB_XXX
values logically OR'd. It should be set to HPMI_CAPABILITY_NOT_SUPPORTED to
indicate that SDB is not supported.

## See also

[HPMI_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/hpmi/ns-hpmi-_hpmi_query_capabilities)

[IOCTL_HPMI_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/hpmi/ni-hpmi-ioctl_hpmi_query_capabilities)

[hpmi.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/hpmi/)