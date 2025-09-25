# SERVICE_TYPE enumeration

## Description

The values of the
**SERVICE_TYPE** enumeration type specify the type of service administered from the SDO API.

## Constants

### `SERVICE_TYPE_IAS:0`

The service is Internet Authentication Service (IAS) or Network Policy Server (NPS).

**Note** Internet Authentication Service was renamed Network Policy Server starting with Windows Server 2008.

### `SERVICE_TYPE_RAS`

The service is the Remote Access Service.

### `SERVICE_TYPE_RAMGMTSVC`

The service is the Remote Access Management Service.

### `SERVICE_TYPE_MAX`

Use this constant to test whether the value is in range.

## See also

[ISdoMachine::GetServiceSDO](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-getservicesdo)