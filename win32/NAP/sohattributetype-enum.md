# SoHAttributeType enumeration

> [!Note]
> The Network Access Protection platform is not available starting with Windows 10

The **SoHAttributeType** enumeration specifies the type of attribute stored in the attribute type-length-value (TLV) object.

## Constants

**sohAttributeTypeSystemHealthId**

Specifies the system health ID attribute type.

**sohAttributeTypeIpv4FixupServers**

Specifies the IPv4 fix-up server attribute type.

**sohAttributeTypeComplianceResultCodes**

Specifies the compliance result code attribute type.

**sohAttributeTypeTimeOfLastUpdate**

Specifies the time of the last update attribute type.

**sohAttributeTypeClientId**

Specifies the client ID attribute type.

**sohAttributeTypeVendorSpecific**

Specifies the vendor-specific attribute type.

**sohAttributeTypeHealthClass**

Specifies the health class attribute type.

**sohAttributeTypeSoftwareVersion**

Specifies the software version attribute type.

**sohAttributeTypeProductName**

Specifies the product name attribute type.

**sohAttributeTypeHealthClassStatus**

Specifies the health class status attribute type.

**sohAttributeTypeSoHGenerationTime**

Specifies the generation time of the Statement of Health attribute type.

**sohAttributeTypeErrorCodes**

Specifies the error code attribute type.

**sohAttributeTypeFailureCategory**

Specifies the failure category attribute type.

**sohAttributeTypeIpv6FixupServers**

Specifies the IPv6 fix-up server attribute type.

**sohAttributeTypeExtendedIsolationState**

Specifies the extended isolation state attribute type.

## Remarks

The [**SoHAttributeValue**](https://learn.microsoft.com/windows/win32/nap/sohattributevalue-union) structure defines the attribute values that correspond to each attribute type.

These attribute types are consumed by the NAP system:

- sohAttributeTypeSystemHealthId
- sohAttributeTypeIpv4FixupServers
- sohAttributeTypeIpv6FixupServers
- sohAttributeTypeComplianceResultCodes
- sohAttributeTypeFailureCategory

The rest of the types are only intended to guide the usage by SHAs and SHVs.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | NapProtocol.h |
| IDL<br> | NapProtocol.idl |

## See also

[**SoHAttributeValue**](https://learn.microsoft.com/windows/win32/nap/sohattributevalue-union)

[**SoHAttribute**](https://learn.microsoft.com/windows/win32/api/naptypes/ns-naptypes-sohattribute)

[**SoH**](https://learn.microsoft.com/windows/win32/api/naptypes/ns-naptypes-soh)

[**INapSoHConstructor**](https://learn.microsoft.com/windows/win32/nap/inapsohconstructor)

[**INapSoHProcessor**](https://learn.microsoft.com/windows/win32/nap/inapsohprocessor)

