# ILayoutStorage::ReLayoutDocfile

## Description

The **ReLayoutDocfile** method rewrites the compound file, using the layout script obtained through monitoring, or provided through explicit layout scripting, to create a new compound file.

## Parameters

### `pwcsNewDfName` [in]

Pointer to the name of the compound file to be rewritten. This name must be a valid filename, distinct from the name of the original compound file. The original compound file will be optimized and written to the new *pwcsNewDfName*.

## Return value

This function supports the standard return values E_OUTOFMEMORY, E_UNEXPECTED, E_INVALIDARG, and E_FAIL, as well as the following:

| Return code | Description |
|----------------|---------------|
|STG_E_INVALIDNAME | The name passed to this function is not a valid file name.|
|STG_E_UNKNOWN | The layout information has been corrupted and cannot be processed.|