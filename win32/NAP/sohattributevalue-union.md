# SoHAttributeValue union

> [!Note]
> The Network Access Protection platform is not available starting with Windows 10

The **SoHAttributeValue** union defines the contents of the **type** member in a [**SoHAttribute**](https://learn.microsoft.com/windows/win32/api/naptypes/ns-naptypes-sohattribute) structure. The structure of the **SoHAttributeValue** union is determined by the [**SoHAttributeType**](https://learn.microsoft.com/windows/win32/nap/sohattributetype-enum) specified in the **type** member of the [**SoHAttribute**](https://learn.microsoft.com/windows/win32/api/naptypes/ns-naptypes-sohattribute) structure.

## Members

**idVal**

**case(sohAttributeTypeSystemHealthId)**

A unique [SystemHealthEntityId](https://learn.microsoft.com/windows/win32/nap/nap-datatypes) that contains the ID of the System Health Agent (SHA) or System Health Validator (SHV) that constructed this [**SoH**](https://learn.microsoft.com/windows/win32/api/naptypes/ns-naptypes-soh) packet.

**v4AddressesVal**

**case(sohAttributeTypeIpv4FixupServers)**

The IPv4 addresses of the fix-up servers in use by the NAP system.

**count**

The number of IPv4 addresses in the **addresses** member in the range 1 to [**maxIpv4CountPerSoHAttribute**](https://learn.microsoft.com/windows/win32/nap/nap-type-constants).

**addresses**

An array of [**Ipv4Address**](https://learn.microsoft.com/windows/win32/api/naptypes/ns-naptypes-ipv4address) structures that contain the IPv4 addresses.

**v6AddressesVal**

**case(sohAttributeTypeIpv6FixupServers)**

The IPv6 addresses of the fix-up servers in use by the NAP system.

**count**

The number of IPv4 addresses in the **addresses** member in the range 1 to [**maxIpv6CountPerSoHAttribute**](https://learn.microsoft.com/windows/win32/nap/nap-type-constants).

**addresses**

An array of [**Ipv6Address**](https://learn.microsoft.com/windows/win32/api/naptypes/ns-naptypes-ipv6address) structures that contain the IPv4 addresses.

**codesVal**

**case(sohAttributeTypeComplianceResultCodes, sohAttributeTypeErrorCodes)**

A [**ResultCodes**](https://learn.microsoft.com/windows/win32/api/naptypes/ns-naptypes-resultcodes) structure that contains either the application defined compliance result codes of the client or [**NAP error constants**](https://learn.microsoft.com/windows/win32/nap/nap-error-constants). An [**SoH**](https://learn.microsoft.com/windows/win32/api/naptypes/ns-naptypes-soh) packet must contain this TLV or the **sohAttributeTypeFailureCategory** TLV.

**dateTimeVal**

**case(sohAttributeTypeTimeOfLastUpdate, sohAttributeTypeSoHGenerationTime)**

A [FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime) structure that contains the time of the last [**SoH**](https://learn.microsoft.com/windows/win32/api/naptypes/ns-naptypes-soh) update or the **SoH** generation time.

**vendorSpecificVal**

**case(sohAttributeTypeVendorSpecific)**

Application-specific data that is defined by the vendor.

**vendorId**

A 4-byte identifier that defines the SHA/SHV pair ID. The first 3 bytes are the IETF-assigned SMI code of the vendor, and the last byte identifies the component itself. When implementing a SHA or SHV, do not use the ID values assigned to internal Microsoft system health components on [**NAP vendor constants**](https://learn.microsoft.com/windows/win32/nap/nap-vendor-constants).

**size**

The size, in bytes, of the vendor data in the range 0 to ([**maxSoHAttributeSize**](https://learn.microsoft.com/windows/win32/nap/nap-type-constants) - 4).

**vendorSpecificData**

A pointer to the vendor specific data in network byte order.

**uint8Val**

**case(sohAttributeTypeHealthClass, sohAttributeTypeFailureCategory,sohAttributeTypeExtendedIsolationState)**

The health class, failure category, or extended isolation state of a NAP component as either a [**HealthClassValue**](https://learn.microsoft.com/windows/win32/nap/healthclassvalue-enum) or [**FailureCategory**](https://learn.microsoft.com/windows/win32/api/naptypes/ne-naptypes-failurecategory) value, or a [**IsolationInfoEx**](https://learn.microsoft.com/windows/win32/api/naptypes/ns-naptypes-isolationinfoex) structure.

**octetStringVal**

**default**

The following attributes' values are octet strings:

- sohAttributeTypeSoftwareVersion
- sohAttributeTypeClientId
- sohAttributeTypeProductName
- sohAttributeTypeHealthClassStatus

For forward compatibility, all unrecognized attributes are returned as octet strings. **data** must be in network byte order.

**size**

The size, in bytes, of **data** in the range 0 to [**maxSoHAttributeSize**](https://learn.microsoft.com/windows/win32/nap/nap-type-constants).

**data**

A pointer to the octet string value.

## Actual data layout

Due to the nature of the SDK publishing environment, unions are not clearly represented in syntax blocks. Here is the actual syntax from the NapProtocol.h header file.

```C++
#include <windows.h>

typedef [switch_type(SoHAttributeType)]
   union tagSoHAttributeValue
   {
      [case(sohAttributeTypeSystemHealthId)]
         SystemHealthEntityId idVal;

      [case(sohAttributeTypeIpv4FixupServers)]
         struct tagIpv4Addresses
         {
            [range(1, maxIpv4CountPerSoHAttribute)]
               UINT16 count;
            [size_is(count)] Ipv4Address* addresses;
         } v4AddressesVal;

      [case(sohAttributeTypeIpv6FixupServers)]
         struct tagIpv6Addresses
         {
            [range(1, maxIpv6CountPerSoHAttribute)]
               UINT16 count;
            [size_is(count)] Ipv6Address* addresses;
         } v6AddressesVal;

      [case(sohAttributeTypeComplianceResultCodes,
            sohAttributeTypeErrorCodes)]
         ResultCodes codesVal;

      [case(sohAttributeTypeTimeOfLastUpdate,
            sohAttributeTypeSoHGenerationTime)]
         FILETIME dateTimeVal;

      [case(sohAttributeTypeVendorSpecific)]
         struct tagVendorSpecific
         {
            UINT32 vendorId;
            [range(0, maxSoHAttributeSize - 4)]
               UINT16 size;
            [size_is(size)] BYTE* vendorSpecificData;
         } vendorSpecificVal;

      [case(sohAttributeTypeHealthClass,
            sohAttributeTypeFailureCategory,
            sohAttributeTypeExtendedIsolationState)]
         UINT8 uint8Val;

      [default]
         struct tagOctetString
         {
            [range(0, maxSoHAttributeSize)] UINT16 size;
            [size_is(size)] BYTE* data;
         } octetStringVal;

   } SoHAttributeValue;
};
```

## Remarks

These attribute types are consumed by the NAP system:

- sohAttributeTypeSystemHealthId
- sohAttributeTypeIpv4FixupServers
- sohAttributeTypeIpv6FixupServers
- sohAttributeTypeComplianceResultCodes
- sohAttributeTypeFailureCategory

The rest of the [**SoHAttributeTypes**](https://learn.microsoft.com/windows/win32/nap/sohattributetype-enum) are meant purely as prescriptive guidance for usage by SHAs and SHVs.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | NapProtocol.h |
| IDL<br> | NapProtocol.idl |

## See also

[NAP Reference](https://learn.microsoft.com/windows/win32/nap/nap-reference)

[NAP Structures](https://learn.microsoft.com/windows/win32/nap/nap-structures)

