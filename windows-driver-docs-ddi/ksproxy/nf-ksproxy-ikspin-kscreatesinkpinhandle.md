# IKsPin::KsCreateSinkPinHandle

## Description

The **KsCreateSinkPinHandle** method creates a pin handle and stores it in the KS pin object.

## Parameters

### `Interface` [in]

A type reference to a [KSPIN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-interface-structure) structure for the interface that **KsCreateSinkPinHandle** negotiated for the created pin.

### `Medium` [in]

A type reference to a [KSPIN_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-medium-structure) structure for the medium that **KsCreateSinkPinHandle** negotiated for the created pin.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

Since the **KsCreateSinkPinHandle** method uses pass-by-reference variables, it is not necessary to pass pointers to KSPIN_INTERFACE and KSPIN_MEDIUM structures as arguments.

After **KsCreateSinkPinHandle** has created a pin handle, you can retrieve the handle by calling the [IKsObject::KsGetObjectHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksobject-ksgetobjecthandle) method.

This method is for proxy use and is not recommended for application use.

## See also

[IKsObject::KsGetObjectHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksobject-ksgetobjecthandle)

[KSPIN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-interface-structure)

[KSPIN_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-medium-structure)