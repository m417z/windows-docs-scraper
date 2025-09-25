# ResUtilGetResourceDependentIPAddressProps function

## Description

Retrieves the [private properties](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/private-properties) of the
first IP Address [dependency](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dependencies) found for a specified
[resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). The **PRESUTIL_GET_RESOURCE_DEPENDENTIP_ADDRESS_PROPS** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle to the resource to query for dependencies.

### `pszAddress` [out]

Output buffer for returning the value of the
[Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-addresses-address) private property.

### `pcchAddress` [in, out]

On input, specifies the size of the *pszAddress* buffer as a count of
**WCHAR**s. On output, specifies the size of the resulting data as a count of
**WCHAR**s that includes the terminating **NULL**.

### `pszSubnetMask` [out]

Output buffer for returning the value of the
[SubnetMask](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-addresses-subnetmask) private property.

### `pcchSubnetMask` [in, out]

On input, specifies the size of the *pszSubnetMask* buffer as a count of
**WCHAR**s. On output, specifies the size of the resulting data as a count of
**WCHAR**s that includes the terminating **NULL**.

### `pszNetwork` [out]

Output buffer for returning the value of the
[Network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-addresses-network) private property.

### `pcchNetwork` [in, out]

On input, specifies the size of the *pszNetwork* buffer as a count of
**WCHAR**s. On output, specifies the size of the resulting data as a count of
**WCHAR**s that includes the terminating **NULL**.

**Windows Server 2008 R2 and Windows Server 2008:** This parameter is named *pcch* prior to Windows Server 2012.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS** (0).

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible error
codes.

| Return code/value | Description |
| --- | --- |
| **ERROR_NO_MORE_ITEMS**<br><br>259 (0x103) | No IP Address dependency was found in the specified resource's list of dependencies. |
| **ERROR_RESOURCE_NOT_PRESENT**<br><br>4316 (0x10DC) | No IP Address dependency was found. |
| **ERROR_MORE_DATA**<br><br>234 (0xEA) | The size of one of the buffers was too small to hold the resulting data. |

## Remarks

Do not call
**ResUtilGetResourceDependentIPAddressProps**
from any resource DLL entry point function.
**ResUtilGetResourceDependentIPAddressProps**
can safely be called from a worker thread. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

The
**ResUtilGetResourceDependentIPAddressProps**
function returns only the private properties for the first IPv4 resource that the resource directly depends on. The
function does not examine indirect dependencies (such as a resource that depends on a
[network Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name) resource that in turn depends on an
[IP Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-address) resource),
[IPv6 Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ipv6-address) resources, or
[IPv6 Tunnel Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ipv6-tunnel-address) resources.

## See also

[ResUtilFindDependentDiskResourceDriveLetter](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilfinddependentdiskresourcedriveletter)

[ResUtilGetResourceDependency](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcedependency)

[ResUtilGetResourceDependencyByClass](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcedependencybyclass)

[ResUtilGetResourceDependencyByName](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcedependencybyname)

[ResUtilGetResourceNameDependency](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcenamedependency)

[Resource Utility Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-utility-functions)