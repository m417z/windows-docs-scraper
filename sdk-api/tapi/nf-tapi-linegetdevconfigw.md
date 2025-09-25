# lineGetDevConfigW function

## Description

The
**lineGetDevConfig** function returns an "opaque" data structure object, the contents of which are specific to the line (service provider) and device class. The data structure object stores the current configuration of a media-stream device associated with the line device.

## Parameters

### `dwDeviceID`

Identifier of the line device to be configured.

### `lpDeviceConfig`

Pointer to the memory location of type
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) where the device configuration structure is returned. Upon successful completion of the request, this location is filled with the device configuration. The **dwStringFormat** member in the
**VARSTRING** structure is set to STRINGFORMAT_BINARY. Prior to calling
**lineGetDevConfig**, the application must set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

**Note** If the size parameters in the structure are not correct, there is a possibility that data could get overwritten. For more information on setting structure sizes, see the
[memory allocation](https://learn.microsoft.com/windows/desktop/Tapi/memory-allocation) topic.

### `lpszDeviceClass`

Pointer to a null-terminated string that specifies the device class of the device whose configuration is requested. Valid device class
[lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid) strings are the same as those specified for the function.

## Return value

Returns zero if the function succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_BADDEVICEID, LINEERR_NODRIVER, LINEERR_INVALDEVICECLASS, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALPOINTER, LINEERR_RESOURCEUNAVAIL, LINEERR_STRUCTURETOOSMALL, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_UNINITIALIZED, LINEERR_NODEVICE.

## Remarks

Call states are device specific.

The
**lineGetDevConfig** function can be used to retrieve a data structure from TAPI that specifies the configuration of a media stream device associated with a particular line device. For example, the contents of this structure could specify data rate, character format, modulation schemes, and error control protocol settings for a "datamodem" media device associated with the line.

Typically, an application calls
[lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid) to identify the media stream device associated with a line, and then calls
[lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineconfigdialog) to allow the user to set up the device configuration. It could then call
**lineGetDevConfig**, and save the configuration information in a phone book (or other database) associated with a particular call destination. When the user later wishes to call the same destination again,
[lineSetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetdevconfig) can be used to restore the configuration settings selected by the user. The functions
**lineSetDevConfig**,
**lineConfigDialog**, and
**lineGetDevConfig** can be used, in that order, to allow the user to view and update the settings.

The exact format of the data contained within the structure is specific to the line and media stream API (device class), is undocumented, and is undefined. The structure returned by this function cannot be directly accessed or manipulated by the application, but can only be stored intact and later used in
[lineSetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetdevconfig) to restore the settings. The structure also cannot necessarily be passed to other devices, even of the same device class (although this can work in some instances, it is not guaranteed).

> [!NOTE]
> The tapi.h header defines lineGetDevConfig as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring)

[lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineconfigdialog)

[lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid)

[lineSetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetdevconfig)