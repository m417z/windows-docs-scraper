# GetAllRecognizers function

## Description

Gets all recognizers.

## Parameters

### `recognizerClsids`

Pointer to the CLSIDs of the recognizers. The CLSID value is created in the registry when you register the recognizer.

### `count`

Pointer to the number of recognizers.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | The parameter is an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was received. |