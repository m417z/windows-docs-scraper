# WSANSCLASSINFOA structure

## Description

The **WSANSCLASSINFO** structure provides individual parameter information for a specific Windows Sockets namespace.

## Members

### `lpszName`

String value associated with the parameter, such as SAPID, TCPPORT, and so forth.

### `dwNameSpace`

GUID associated with the namespace.

### `dwValueType`

Value type for the parameter, such as REG_DWORD or REG_SZ, and so forth.

### `dwValueSize`

Size of the parameter provided in **lpValue**, in bytes.

### `lpValue`

Pointer to the value of the parameter.

## Remarks

The **WSANSCLASSINFO** structure is defined differently depending on whether ANSI or UNICODE is used. The above syntax block applies to ANSI; for UNICODE, the datatype for **lpszName** is **LPWSTR**.

> [!NOTE]
> The winsock2.h header defines WSANSCLASSINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WSASERVICECLASSINFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaserviceclassinfow)