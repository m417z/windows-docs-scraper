# IPrintCorePS2::GetOptionAttribute

## Description

The `IPrintCorePS2::GetOptionAttribute` method retrieves the option attribute list or the value of a specific option attribute.

## Parameters

### `pdevobj` [in]

Pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `dwFlags` [in]

Is reserved and must be set to zero.

### `pszFeatureKeyword` [in]

Pointer to a caller-supplied buffer containing an ASCII string specifying the single feature keyword to query for.

### `pszOptionKeyword` [in]

Pointer to a caller-supplied buffer containing an ASCII string specifying the single option keyword to query for. This value can be obtained from a prior call to [IPrintCorePS2::EnumOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreps2-enumoptions).

### `pszAttribute` [in]

Pointer to a caller-supplied buffer containing an ASCII string specifying the single attribute requested. If this parameter is **NULL**, the caller is requesting a list of all supported attribute names for the option, as opposed to specifying a specific attribute name for the option.

### `pdwDataType` [out]

Pointer to a memory location that receives a value specifying the data type of the requested attribute. This value is an enumerator of the [EATTRIBUTE_DATATYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ne-printoem-_eattribute_datatype) enumeration, which is defined in printoem.h.

### `pbData` [out]

Pointer to a caller-supplied buffer that receives the requested data. To simply query for the number of bytes needed to fulfill a request, set this parameter to **NULL**.

### `cbSize` [in]

Specifies the size, in bytes of the buffer pointed to by *pbData*.

### `pcbNeeded` [out]

Pointer to a memory location that receives the actual size, in bytes, of the requested data.

## Return value

This method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | The value in *cbSize* was smaller than the number of bytes to be written to the output buffer (the buffer pointed to by *pbData*).<br><br>The method was called with *pbData* set to **NULL**. |
| **E_INVALIDARG** | The method attempted to query for a nonexistent attribute.<br><br>The feature keyword name or option keyword name were not recognized.<br><br>The *pdevobj* parameter pointed to an invalid driver context object. |
| **E_FAIL** | The method failed. |

## Remarks

If this method is called with its *pszAttribute* and *pbData* parameters set to **NULL**, the method returns with **pcbNeeded* set to the number of bytes needed for the list of all supported attribute names for the option. If the method is called a second time, with *pszAttribute* set to **NULL** and *pbData* pointing to a buffer of the size specified in **pcbNeeded* in the previous call, the method returns with **pdwDataType* set to kADT_ASCII (an enumerator of the [EATTRIBUTE_DATATYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ne-printoem-_eattribute_datatype) enumerated type) and *pbData* pointing to a null-delimited list of all the supported attribute names for the option. This list is terminated with two null characters.

To reduce the need to make two calls per data access, pass the method an output buffer of a fixed size (1 KB, for example), and then check the function return value. If the method returns S_OK, the buffer already contains the data of interest. If the method returns E_OUTOFMEMORY, the value in **pcbNeeded* is the buffer size needed to hold the data of interest. The caller should then allocate a buffer of that larger size and proceed with a second call to the method.

This method is supported for any Pscript5 render plug-in.

For more information, see [Using GetOptionAttribute](https://learn.microsoft.com/windows-hardware/drivers/print/using-getoptionattribute).

## See also

[DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj)

[IPrintCorePS2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcoreps2)

[IPrintCorePS2::EnumOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreps2-enumoptions)

[IPrintCorePS2::GetFeatureAttribute](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreps2-getfeatureattribute)

[IPrintCorePS2::GetGlobalAttribute](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreps2-getglobalattribute)