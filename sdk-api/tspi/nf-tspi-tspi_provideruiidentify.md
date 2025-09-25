# TSPI_providerUIIdentify function

## Description

The
**TSPI_providerUIIdentify** function extracts from the service provider the fully qualified path to load the service provider's UI DLL component.

Implementation is mandatory if the service provider implements any UI DLL functions.

## Parameters

### `lpszUIDLLName`

Pointer to a block of memory at least MAX_PATH in length, into which the service provider must copy a null-terminated string specifying the fully qualified path for the DLL containing the service provider functions which must execute in the process of the calling application.

## Return value

Returns zero if successful. Shouldn't ever fail, but if it does returns one of these negative error values:

LINEERR_NOMEM, LINEERR_OPERATIONFAILED.