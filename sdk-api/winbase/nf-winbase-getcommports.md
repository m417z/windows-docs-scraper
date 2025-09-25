# GetCommPorts function

## Description

Gets an array that contains the well-formed COM ports.

This function obtains the COM port numbers from the **HKLM\Hardware\DeviceMap\SERIALCOMM** registry key and then writes them to a caller-supplied array. If the array is too small, the function gets the necessary size.

**Note** If new entries are added to the registry key, the necessary size can change between API calls.

## Parameters

### `lpPortNumbers` [out]

An array for the port numbers.

### `uPortNumbersCount` [in]

The length of the array in the *lpPortNumbers* parameter.

### `puPortNumbersFound` [out]

The number of port numbers written to the *lpPortNumbers* or the length of the array required for the port numbers.

## Return value

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The call succeeded. The *lpPortNumbers* array was large enough for the result. |
| **ERROR_MORE_DATA** | The *lpPortNumbers* array was too small to contain all available port numbers. |
| **ERROR_FILE_NOT_FOUND** | There are no comm ports available. |