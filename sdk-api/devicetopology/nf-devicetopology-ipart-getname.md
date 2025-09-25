# IPart::GetName

## Description

The **GetName** method gets the friendly name of this part.

## Parameters

### `ppwstrName` [out]

Pointer to a pointer variable into which the method writes the address of a null-terminated, wide-character string that contains the friendly name of this part. The method allocates the storage for the string. The caller is responsible for freeing the storage, when it is no longer needed, by calling the **CoTaskMemFree** function. If the **GetName** call fails, **ppwstrName* is **NULL**. For information about **CoTaskMemFree**, see the Windows SDK documentation.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *ppwstrName* is **NULL**. |

## See also

[IPart Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart)