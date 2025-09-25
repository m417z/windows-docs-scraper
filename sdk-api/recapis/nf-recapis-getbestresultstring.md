# GetBestResultString function

## Description

Retrieves the best result string.

## Parameters

### `hrc`

Handle to the recognizer context.

### `pcSize`

On input, the number of characters the *pwcBestResult* buffer can hold. On output, the number of characters the *pwcBestResult* buffer contains. If *pwcBestResult* is **NULL**, the function returns the required size of the buffer that you use to allocate the *pwcBestResult* buffer.

### `pwcBestResult`

Recognition result. If the buffer is too small, the function truncates the string. The string is not **NULL**-terminated. To determine the required size of the buffer, set *pwcBestResult* to **NULL**; use *pcSize* to allocate the *pwcBestResult* buffer.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success.<br><br>For Latin and East Asian recognizers this result in combination with an empty string in *pwcBestResult* means that no recognition result exists. |
| **TPC_S_TRUNCATED** | The string is truncated to fit in the *pwcBestResult* buffer. |
| **E_POINTER** | One of the parameters is an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was received. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **TPC_E_NOT_RELEVANT** | The recognizer context does not contain results. |