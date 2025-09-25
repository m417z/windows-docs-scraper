# IBackgroundCopyGroup::GetProp

## Description

[**IBackgroundCopyGroup** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Use the **GetProp** method to retrieve a property value from the group.

## Parameters

### `propID` [in]

Identifies the property to retrieve. For a list of properties, see the [GROUPPROP](https://learn.microsoft.com/windows/desktop/api/qmgr/ne-qmgr-groupprop) enumeration.

### `pvarVal` [out]

Property value.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully retrieved the property. |
| **E_NOTIMPL** | You specified a property that is not supported. |
| **E_INVALIDARG** | You specified a variant type that is not compatible with the property. |

## See also

[IBackgroundCopyGroup](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopygroup)