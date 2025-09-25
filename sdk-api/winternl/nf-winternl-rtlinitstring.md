# RtlInitString function

## Description

Initializes a counted string.

## Parameters

### `DestinationString` [in, out]

The counted string to be initialized. The *DestinationString* is initialized to point to the *SourceString*. The **Length** and **MaximumLength** fields of the *DestinationString* are initialized to the length of the *SourceString*.

### `SourceString` [in]

A pointer to a null-terminated string. If the *SourceString* is not specified, the **Length** and **MaximumLength** fields of the *DestinationString* are initialized to zero.

## Remarks

**Security Warning:** Do not allow the *SourceString* parameter size to exceed **MAX_USHORT** characters.

Because there is no import library for this function, you must use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).

**Note** **RtlInitString** is available in Windows XP. It might be altered or unavailable in subsequent versions.