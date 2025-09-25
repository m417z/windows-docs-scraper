# IComponents::EnumComponents

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **EnumComponents** method returns an enumerator for the components in the collection.

## Parameters

### `ppNewEnum` [out]

Address of a variable that receives an [IEnumComponents](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ienumcomponents) interface pointer.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

If the method succeeds, the **IEnumComponents** interface has an outstanding reference count. The caller must release the interface.

## See also

[IComponents Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponents)