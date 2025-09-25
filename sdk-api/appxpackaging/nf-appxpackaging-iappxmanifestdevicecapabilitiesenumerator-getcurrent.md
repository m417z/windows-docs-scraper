# IAppxManifestDeviceCapabilitiesEnumerator::GetCurrent

## Description

Gets the device capability at the current position of the enumerator.

## Parameters

### `deviceCapability` [out, retval]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The current device capability.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **E_BOUNDS** | The enumerator has passed the last item in the collection. |

## Remarks

The caller must free the memory allocated for *deviceCapability* using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

The enumerator returned can be empty. In this case, a call to [GetHasCurrent](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxmanifestdevicecapabilitiesenumerator-gethascurrent) returns **false**. If the enumerator is not empty, it points to the first element, and this method returns the first item. Subsequently, the user should use [MoveNext](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxmanifestdevicecapabilitiesenumerator-movenext) to move through the items, and call **GetHasCurrent** before using **GetCurrent** to access the item.

## See also

[IAppxManifestDeviceCapabilitiesEnumerator](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestdevicecapabilitiesenumerator)