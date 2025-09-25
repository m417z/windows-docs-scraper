# SERVICE_INFOA structure

## Description

The
**SERVICE_INFO** structure contains information about a network service or a network service type.

## Members

### `lpServiceType`

Type: **LPGUID**

A pointer to a GUID that is the type of the network service.

### `lpServiceName`

Type: **LPTSTR**

A pointer to a **NULL**-terminated string that is the name of the network service.

If you are calling the
**SetService** function with the *dwNameSpace* parameter set to NS_DEFAULT, the network service name must be a common name. A common name is what the network service is commonly known as. An example of a common name for a network service is "My SQL Server".

If you are calling the
**SetService** function with the *dwNameSpace* parameter set to a specific service name, the network service name can be a common name or a distinguished name. A distinguished name distinguishes the service to a unique location with a directory service. An example of a distinguished name for a network service is "MS\\SYS\\NT\\DEV\\My SQL Server".

### `lpComment`

Type: **LPTSTR**

A pointer to a **NULL**-terminated string that is a comment or description for the network service. For example, "Used for development upgrades."

### `lpLocale`

Type: **LPTSTR**

A pointer to a **NULL**-terminated string that contains locale information.

### `dwDisplayHint`

Type: **DWORD**

A hint as to how to display the network service in a network browsing user interface. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **RESOURCEDISPLAYTYPE_DOMAIN** | Display the network service as a domain. |
| **RESOURCEDISPLAYTYPE_FILE** | Display the network service as a file. |
| **RESOURCEDISPLAYTYPE_GENERIC** | The method used to display the object does not matter. |
| **RESOURCEDISPLAYTYPE_GROUP** | Display the network service as a group. |
| **RESOURCEDISPLAYTYPE_SERVER** | Display the network service as a server. |
| **RESOURCEDISPLAYTYPE_SHARE** | Display the network service as a sharepoint. |
| **RESOURCEDISPLAYTYPE_TREE** | Display the network service as a tree. |

### `dwVersion`

Type: **DWORD**

The version for the network service. The high word of this value specifies a major version number. The low word of this value specifies a minor version number.

### `dwTime`

Type: **DWORD**

Reserved for future use. Must be zero.

### `lpMachineName`

Type: **LPTSTR**

A pointer to a **NULL**-terminated string that is the name of the computer on which the network service is running.

### `lpServiceAddress`

Type: **LPSERVICE_ADDRESSES**

A pointer to a
[SERVICE_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_addresses) structure that contains an array of
[SERVICE_ADDRESS](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_address) structures. Each
**SERVICE_ADDRESS** structure contains information about a network service address.

A network service can call the
[getsockname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockname) function to determine the local address of the system.

### `ServiceSpecificInfo`

Type: **BLOB**

A
[BLOB](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-blob) structure that specifies service-defined information.

**Note** In general, the data pointed to by the
[BLOB](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-blob) structure's **pBlobData** member must not contain any pointers. That is because only the network service knows the format of the data; copying the data without such knowledge would lead to pointer invalidation. If the data pointed to by **pBlobData** contains variable-sized elements, offsets from **pBlobData** can be used to indicate the location of those elements. There is one exception to this general rule: when **pBlobData** points to a
[SERVICE_TYPE_INFO_ABS](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_type_info_absa) structure. This is possible because both the
**SERVICE_TYPE_INFO_ABS** structure, and any
[SERVICE_TYPE_VALUE_ABS](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_type_value_absa) structures it contains are predefined, and thus their formats are known to the operating system.

## See also

[BLOB](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-blob)

[GetService](https://learn.microsoft.com/windows/desktop/api/nspapi/nf-nspapi-getservicea)

[NS_SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-ns_service_infoa)

[SERVICE_ADDRESS](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_address)

[SERVICE_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_addresses)

[SERVICE_TYPE_INFO_ABS](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_type_info_absa)

[SERVICE_TYPE_VALUE_ABS](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_type_value_absa)

[SetService](https://learn.microsoft.com/windows/desktop/api/nspapi/nf-nspapi-setservicea)

## Remarks

> [!NOTE]
> The nspapi.h header defines SERVICE_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).