# ADDRESS_CAPABILITY_STRING enumeration

## Description

The
**ADDRESS_CAPABILITY_STRING** enum is used to check on address capabilities which are described by strings.

## Constants

### `ACS_PROTOCOL:0`

Describes a protocol-specific capability. The value is returned as a GUID in string format. For possible values, see
[TAPIPROTOCOL_](https://learn.microsoft.com/windows/desktop/Tapi/tapiprotocol--constants). A TSP may define additional values. Corresponds to the **ProtocolGuid** member of TAPI 2's
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) structure.

### `ACS_ADDRESSDEVICESPECIFIC`

Describes an address device-specific capability. The value is TSP dependent and can be a structure, a string, or some other type. An application should use the **BSTR** pointer received from Tapi3.dll as a pointer to an array of bytes (a buffer), and then interpret the buffer according to TSP specifications. Corresponds to the **dwDevSpecific** and **dwDevSpecificSize** members of TAPI 2's
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps) structure.

### `ACS_LINEDEVICESPECIFIC`

Describes a line device-specific capability. The value is TSP dependent and can be a structure, a string, or some other type. An application should use the **BSTR** pointer received from Tapi3.dll as a pointer to an array of bytes (a buffer), and then interpret the buffer according to TSP specifications. Corresponds to the **dwDevSpecific** and **dwDevSpecificSize** members of TAPI 2's
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) structure.

### `ACS_PROVIDERSPECIFIC`

Describes a provider-specific capability. The value is a plain string. It can be used with regular **BSTR** functions for operations such as printing and concatenating. A specific TSP might included embedded **NULL** characters inside these strings. If so, an application should take care when printing the value. If the embedded **NULL** characters are not replaced with blanks, the strings will appear truncated when printed. Corresponds to the **dwProviderInfoSize** and **dwProviderInfoOffset** members of TAPI 2's
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) structure.

### `ACS_SWITCHSPECIFIC`

Describes a switch-specific capability. The value is a plain string. It can be used with regular **BSTR** functions for operations such as printing and concatenating. A specific TSP might included embedded **NULL** characters inside these strings. If so, an application should take care when printing the value. If the embedded **NULL** characters are not replaced with blanks, the strings will appear truncated when printed. Corresponds to the **dwSwitchInfoSize** and **dwSwitchInfoOffset** members of TAPI 2's
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) structure.

### `ACS_PERMANENTDEVICEGUID`

Describes the GUID of a permanent device. The value is returned as a GUID in string format. This identifier must remain stable throughout, including operating system upgrades. Corresponds to the **PermanentLineGuid** member of TAPI 2's
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) structure.

## See also

[Address object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITAddressCapabilities::get_AddressCapabilityString](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddresscapabilities-get_addresscapabilitystring)

[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[TAPIPROTOCOL_](https://learn.microsoft.com/windows/desktop/Tapi/tapiprotocol--constants)