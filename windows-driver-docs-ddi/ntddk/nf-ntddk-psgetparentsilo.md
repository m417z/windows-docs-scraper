# PsGetParentSilo function

## Description

Retrieves the most immediate parent silo in the hierarchy
for a given job object.

## Parameters

### `Job` [in, optional]

A pointer to an **EJOB** structure that represents the job object.

## Return value

A pointer to the parent silo of the job. This value may be
PSP_HOST_SILO, because all silos descend from the host.