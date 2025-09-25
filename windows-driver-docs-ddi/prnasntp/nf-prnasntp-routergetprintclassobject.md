# RouterGetPrintClassObject function

## Description

The `RouterGetPrintClassObject` function enumerates the list of print providers, searching for the print provider with the specified name and interface ID.

## Parameters

### `pPrinter` [in]

A pointer to a null-terminated string that contains the name of the printer or print server.

### `riid` [in]

The identifier of the requested COM interface.

### `ppv` [out]

A pointer to a variable that supplies the address of the COM interface requested in the *iid* parameter.

## Return value

This function returns S_OK on success, and a standard COM error code otherwise.