# KsPinGetConnectedPinFileObject function

## Description

The **KsPinGetConnectedPinFileObject** function returns the file object for the pin to which *Pin* is connected. Works only for source pins.

## Parameters

### `Pin` [in]

A pointer to a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure that is the AVStream pin object for which to acquire the file object for the connected pin.

## Return value

If *Pin* is a source pin, **KsPinGetConnectedPinFileObject** returns a pointer to the [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure for the pin to which *Pin* is connected. If *Pin* is not a source pin, it returns **NULL**.

## See also

[KsPinGetConnectedFilterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetconnectedfilterinterface)

[KsPinGetConnectedPinInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetconnectedpininterface)