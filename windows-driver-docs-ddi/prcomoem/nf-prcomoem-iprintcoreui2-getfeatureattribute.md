# IPrintCoreUI2::GetFeatureAttribute

## Description

The `IPrintCoreUI2::GetFeatureAttribute` method retrieves the feature attribute list or the value of a specific feature attribute.

## Parameters

### `poemuiobj` [in]

Pointer to the current context, an [OEMUIOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiobj) structure.

### `dwFlags` [in]

Is reserved and must be set to zero.

### `pszFeatureKeyword` [in]

Pointer to a caller-supplied buffer containing an ASCII string specifying the single feature keyword to query for. This value can be obtained from a prior call to [IPrintCoreUI2::EnumFeatures](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreui2-enumfeatures).

### `pszAttribute` [in]

Pointer to a caller-supplied buffer containing an ASCII string specifying the single attribute requested. If this parameter is **NULL**, the caller is requesting a list of all supported feature attribute names, as opposed to specifying a specific feature attribute name.

### `pdwDataType` [out]

Pointer to a memory location that receives a value specifying the data type of the requested attribute. This value is an enumerator of the [EATTRIBUTE_DATATYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ne-printoem-_eattribute_datatype) enumeration, which is defined in printoem.h.

### `pbData` [out]

Pointer to a caller-supplied buffer that receives the requested data. To simply query for the number of bytes needed to fulfill a request, set this parameter to **NULL**.

### `cbSize` [in]

Specifies the size, in bytes of the buffer pointed to by `pbData`.

### `pcbNeeded` [out]

Pointer to a memory location that receives the actual size, in bytes, of the requested data.

## Return value

This method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | The value in *cbSize* was smaller than the number of bytes to be written to the output buffer (the buffer pointed to by *pbData*).<br><br>The method was called with *pbData* set to **NULL**. |
| **E_INVALIDARG** | The method attempted to query for a nonexistent attribute.<br><br>The feature keyword was not recognized.<br><br>The *poemuiobj* parameter pointed to an invalid context object. |
| **E_FAIL** | The method failed |

## Remarks

This method is supported only for Windows XP Pscript5 plug-ins, not for Unidrv plug-ins.

If this method is called with its *pszAttribute* and *pbData* parameters set to **NULL**, the method returns with **pcbNeeded* set to the number of bytes needed for the list of all supported attribute names for the feature. If the method is called a second time, with *pszAttribute* set to **NULL** and *pbData* pointing to a buffer of the size specified in **pcbNeeded* in the previous call, the method returns with **pdwDataType* set to kADT_ASCII (an enumerator of the [EATTRIBUTE_DATATYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ne-printoem-_eattribute_datatype) enumerated type) and *pbData* pointing to a null-delimited list of all supported attribute names for the feature. This list is terminated with two null characters.

To reduce the need to make two calls per data access, pass the method an output buffer of a fixed size (1 KB, for example), and then check the function return value. If the method returns S_OK, the buffer already contains the data of interest. If the method returns E_OUTOFMEMORY, the value in **pcbNeeded* is the buffer size needed to hold the data of interest. The caller should then allocate a buffer of that larger size and proceed with a second call to the method.

For more information, see [Using GetFeatureAttribute](https://learn.microsoft.com/windows-hardware/drivers/print/using-getfeatureattribute).

## See also

[IPrintCoreUI2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcoreui2)

[IPrintCoreUI2::EnumFeatures](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreui2-enumfeatures)

[IPrintCoreUI2::GetGlobalAttribute](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreui2-getglobalattribute)

[IPrintCoreUI2::GetOptionAttribute](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreui2-getoptionattribute)

[OEMUIOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiobj)