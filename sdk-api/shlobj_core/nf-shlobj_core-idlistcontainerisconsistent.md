# IDListContainerIsConsistent function

## Description

Verifies that the container structure of an IDList is valid.

## Parameters

### `pidl` [in]

A pointer to the IDList to validate.

### `cbAlloc` [in]

The size, in bytes, of the PIDL specified in the *pidl* parameter.

## Return value

**TRUE** if the IDList structure is valid; otherwise, **FALSE**.

## Remarks

This function should be used by any code that reads an IDList from a persisted format to ensure that invalid forms do not lead to a security exploit in the code that interprets the IDList. Shell data sources are responsible for validating private sections of the ITEMIDs. Hidden data is validated by the functions that interpret that data.