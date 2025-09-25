# RtlInitUnicodeString function

## Description

Initializes a counted Unicode string.

## Parameters

### `DestinationString` [in, out]

The buffer for a counted Unicode string to be initialized. The length is initialized to zero if the *SourceString* is not specified.

### `SourceString` [in, optional]

Optional pointer to a null-terminated Unicode string with
which to initialize the counted string.