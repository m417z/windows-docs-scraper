# IPart::GetGlobalId

## Description

The **GetGlobalId** method gets the global ID of this part.

## Parameters

### `ppwstrGlobalId` [out]

Pointer to a pointer variable into which the method writes the address of a null-terminated, wide-character string that contains the global ID. The method allocates the storage for the string. The caller is responsible for freeing the storage, when it is no longer needed, by calling the **CoTaskMemFree** function. If the **GetGlobalId** call fails, **ppwstrGlobalId* is **NULL**. For information about **CoTaskMemFree**, see the Windows SDK documentation.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *ppwstrGlobalId* is **NULL**. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

A global ID is a string that uniquely identifies a part among all parts in all device topologies in the system. Clients should treat this string as opaque. That is, clients should *not* attempt to parse the contents of the string to obtain information about the part. The reason is that the string format is undefined and might change from one implementation of the DeviceTopology API to the next.

## See also

[IPart Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart)