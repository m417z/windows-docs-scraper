## Description

The **IPrintCoreHelperPS::GetFeatureAttribute** method retrieves the feature attribute list or the value of a specific feature attribute.

## Parameters

### `pszFeatureKeyword` [in]

A pointer to a caller-supplied buffer that contains an ANSI string that specifies the feature keyword to query for. This value can be obtained from a prior call to [IPrintCoreHelperPS::EnumFeatures](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelperps-enumfeatures).

### `pszAttribute` [in]

A pointer to a caller-supplied buffer that contains an ANSI string that specifies the attribute that was requested. If this parameter is **NULL**, the caller is requesting a list of all of the supported feature attribute names instead of specifying a specific feature attribute name.

### `pdwDataType` [out]

A pointer to a variable that receives a value that specifies the data type of the requested attribute. This value is an enumerator of the [EATTRIBUTE_DATATYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ne-printoem-_eattribute_datatype) enumeration type, which is defined in printoem.h.

### `ppbData` [out]

A pointer to a callee-allocated buffer containing the requested data. Upon completion of this method, the caller does not need to release this buffer.

### `pcbSize` [out]

A pointer to a variable that receives the size, in bytes, of the buffer that is pointed to by the *pbData* parameter.

## Return value

**IPrintCoreHelperPS::GetFeatureAttribute** should return one of the following values.

| Return code | Description |
|--|--|
| **S_OK** | The method succeeded. |
| **E_FAIL** | The method failed. |
| **E_INVALIDARG** | The method attempted to query for a nonexistent attribute. This value might also mean that the feature keyword was not recognized. |
| **E_OUTOFMEMORY** | The value in *pcbSize* was smaller than the number of bytes to be written to the output buffer that is pointed to by *pbData*. This value might also mean that the method was called with *pbData* set to **NULL**. |

## Remarks

If **IPrintCoreHelperPS::GetFeatureAttribute** is called with its *pszAttribute* and *pbData* parameters set to **NULL**, the method returns with *pcbSize* set to the number of bytes that are needed for the list of all of the supported attribute names for the feature. If this method is called a second time, with *pszAttribute* set to **NULL** and *pbData* pointing to a buffer of the size that was specified in *pcbSize* in the previous call, the method returns with *pdwDataType* set to kADT_ASCII (an enumerator of the [EATTRIBUTE_DATATYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ne-printoem-_eattribute_datatype) enumeration type) and *pbData* pointing to a NULL-delimited list of all of the supported attribute names for the feature. This list is terminated with two null characters.

For more information about **IPrintCoreHelperPS::GetFeatureAttribute**, see [Using GetFeatureAttribute](https://learn.microsoft.com/windows-hardware/drivers/print/using-getfeatureattribute).

## See also

[IPrintCoreHelperPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperps)

[IPrintCoreHelperPS::GetGlobalAttribute](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelperps-getglobalattribute)

[IPrintCoreHelperPS::GetOptionAttribute](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelperps-getoptionattribute)