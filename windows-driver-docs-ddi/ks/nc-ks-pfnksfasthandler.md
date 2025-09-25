# PFNKSFASTHANDLER callback function

## Description

*KStrFastHandler* is a driver-supplied routine that handles a property or method request without the creation of an IRP.

## Parameters

### `FileObject` [in]

Specifies the file object on which the request was made.

### `Request` [in]

Specifies the original property parameter. This will always be on FILE_LONG_ALIGNMENT, but cannot be on FILE_QUAD_ALIGNMENT.

### `RequestLength` [in]

Specifies the length indicated by the caller of the property parameter.

### `Data` [in, out]

Specifies the original unaligned data parameter.

### `DataLength` [in]

Specifies the length indicated by the caller of the data parameter.

### `IoStatus` [out]

Specifies an aligned structure that is used to return error status and information. This information is then copied to the original I/O status structure on completion.

## Return value

*KStrFastHandler* returns **TRUE** if the call was handled. If the call was not handled, it returns **FALSE** and an IRP is generated to handle the request.

## Remarks

The minidriver provides an entry point for this routine in [KSFASTPROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksfastproperty_item) or [KSFASTMETHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksfastmethod_item).