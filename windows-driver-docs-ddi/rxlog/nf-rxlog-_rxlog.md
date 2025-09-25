# _RxLog function

## Description

**_RxLog** is a part of the RDBSS (Redirected Drive Buffering SubSystem) debug logging facilities. It takes a format string and variable number of parameters and formats an output string for recording as an I/O error log entry if logging is enabled.

## Parameters

### `format`

Pointer to a variable argument list that contains a format string and a variable number of format specifiers that are replaced by the values of subsequent arguments.

### `...`

Variable number of arguments that correspond to the format specifies in the **format** string. These arguments provide the data to be logged, such as strings, integers, and so forth.

## Remarks

It is recommended that the **RxLog** macro be used instead of calling the **_RxLog** routine directly. On retail builds, the **RxLog** macro is defined to nothing.

If logging is enabled, **_RxLog** will output a string for recording as an I/O error log entry based on the format string and number of variables passed.

The **_RxLog** routine supports the following format string descriptors:

* %lN, %wN, %lS, %wS, %ld, %wd--a number
* %x--a hexadecimal number
* %c--a character
* %s--an ASCII string
* %Z--a Unicode string that contains ASCII characters

The **_RxLog** routine is limited to an output string of, at most, 48 lines, so the **format** string can't contain more than 48 '\n' characters.

## See also

[**RxLogEventDirect**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxlogeventdirect)

[**RxLogEventWithAnnotation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxlogeventwithannotation)

[**RxLogEventWithBufferDirect**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxlogeventwithbufferdirect)