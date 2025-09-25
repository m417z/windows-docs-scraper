# IBrowserService2::Offline

## Description

Deprecated. Checks for and updates the browser's offline status, synchronizing the state between the base class and any derived classes.

## Parameters

### `iCmd` [in]

Type: **int**

One of the following commands.

#### SBSC_QUERY

Queries the offline state. The method's return value contains the answer.

#### SBSC_TOGGLE

Toggles the offline state.

## Return value

Type: **HRESULT**

In the case of SBSC_TOGGLE, returns standard error codes. In the case of SBSC_QUERY, returns S_OK if offline, S_FALSE otherwise.