# TSPI_lineGetDevConfig function

## Description

The
**TSPI_lineGetDevConfig** function returns a data structure object, the contents of which are specific to the line (service provider) and device class, giving the current configuration of a device associated one-to-one with the line device.

## Parameters

### `dwDeviceID`

The line device to be configured.

### `lpDeviceConfig`

A pointer to a data structure of type
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) where the device configuration structure of the associated device is returned. Upon successful completion of the request, the service provider fills this data structure with the device configuration. The **dwStringFormat** member in the
**VARSTRING** structure must be set to STRINGFORMAT_BINARY. If the **dwTotalSize** member of the
**VARSTRING** structure pointed to by the *lpDeviceConfig* parameter is greater than or equal to the size of the fixed portion of the structure, the service provider sets the **dwNeededSize** member to the required size and returns zero.

### `lpszDeviceClass`

A pointer to a null-terminated Unicode string that specifies the device class of the device whose configuration is requested. Valid device class strings are the same as those specified for the
[TSPI_lineGetID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetid) function when it is applied to a line device (*dwSelect* has the value LINECALLSELECT_LINE).

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALDEVICECLASS, LINEERR_NOMEM, LINEERR_INVALPOINTER, LINEERR_OPERATIONUNAVAIL, LINEERR_STRUCTURETOOSMALL, LINEERR_OPERATIONFAILED, LINEERR_NODRIVER, LINEERR_RESOURCEUNAVAIL.

## Remarks

The call state is device-specific.

This function can be used to retrieve a data structure from the service provider that specifies the configuration of a device associated one-to-one with the line device. The *lpszDeviceClass* parameter selects which of among possibly several different classes of devices is to have its configuration retrieved. The set of supported classes is restricted to those whose devices correspond one-to-one with the line device. For more information about common device classes, see
[TSPI Device Classes](https://learn.microsoft.com/windows/desktop/Tapi/tspi-device-classes).

A service provider should typically allow the tapi/line device class under this function. It would retrieve parameters that have "line" scope, such as the list of addresses in this line, the list of physical hardware devices such as COMM ports corresponding to the addresses, maximum number of concurrent calls (if configurable), and so on.

In general, this function does not allow media-related device classes such as mci waveaudio, low level wave, or datamodem device classes, because these usually apply to a particular call or a particular address. Because there can be more than one of these per line device, the identification of the particular call or address simply by the line device identifier parameter in this function would be ambiguous. An exception can be made for call-specific or address-specific device classes in cases where there is class configuration information that applies to the entire line device scope, such as initial defaults, and so on.

There are several reasons why exceptional support for call-specific and address-specific device classes is of only limited value under this function. First, because these classes can be ambiguous on multiple-address/multiple-call service providers, only a subset of service providers support them. Applications are not likely to add a device-specific dependency on the inclusion of these classes in this function. Second, as higher-level media "classes" emerge that implement high-level protocols such as dial-in file system access in terms of low-level transport APIs, configuration for these classes tends toward "instance" scope instead of "class" scope. The high-level media API must supply its own functions to configure call-specific or address-specific instances.

Whatever sort of devices and device classes this function supports, it can potentially affect two kinds of configuration information: permanent and temporary. Permanent information survives across different "opens" of the line, and even across different "inits" of the service provider itself. Temporary information survives only within a unique "open" of the line. When the line is closed, any such temporary information that has been retrieved or set through
[TSPI_lineSetDevConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetdevconfig) can revert to default or undefined values. The caller can reliably retrieve any temporary configuration only by a sequence such as
[TSPI_lineOpen](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineopen),
[TSPI_lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineconfigdialog),
**TSPI_lineGetDevConfig**. The caller can reliably set temporary configuration information retrieved by such a sequence through a sequence such as
**TSPI_lineOpen**,
**TSPI_lineSetDevConfig**. The temporary part of configuration remains stable only until the next
**TSPI_lineConfigDialog**,
**TSPI_lineSetDevConfig**, or
[TSPI_lineClose](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineclose). The service provider must take care of storing any permanent part of the configuration, typically in an .ini file, and reloading it whenever the service provider is initialized.

The exact format of the data contained within the structure returned by this function is specific to the line and device class API, is undocumented, and is undefined. The structure returned by this function cannot be directly accessed or manipulated by the application, but can only be stored intact and later used in
[TSPI_lineSetDevConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetdevconfig) to restore the settings. The structure also cannot necessarily be passed to other devices, even of the same device class (although this may work in some instances, it is not guaranteed). A service provider should put items in the data structure to allow it to be checked for consistency to guard against failures due to a client application passing incompatible information.

## See also

[TSPI_lineClose](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineclose)

[TSPI_lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineconfigdialog)

[TSPI_lineGetID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetid)

[TSPI_lineOpen](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineopen)

[TSPI_lineSetDevConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetdevconfig)

[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring)