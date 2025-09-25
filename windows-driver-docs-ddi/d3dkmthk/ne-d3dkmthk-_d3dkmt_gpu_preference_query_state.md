# D3DKMT_GPU_PREFERENCE_QUERY_STATE enumeration

## Description

A **D3DKMT_GPU_PREFERENCE_QUERY_STATE** value specifies the GPU preference for a query.

## Constants

### `D3DKMT_GPU_PREFERENCE_STATE_UNINITIALIZED`

The GPU preference isn't initialized.

### `D3DKMT_GPU_PREFERENCE_STATE_HIGH_PERFORMANCE`

The highest performing GPU is preferred.

### `D3DKMT_GPU_PREFERENCE_STATE_MINIMUM_POWER`

The minimum-powered GPU is preferred.

### `D3DKMT_GPU_PREFERENCE_STATE_UNSPECIFIED`

A GPU preference isn't specified.

### `D3DKMT_GPU_PREFERENCE_STATE_NOT_FOUND`

The GPU preference isn't found.

### `D3DKMT_GPU_PREFERENCE_USER_SPECIFIED_GPU`

The GPU preference is specified by the user.

## Remarks

The user preference should be one of the following three options:

* D3DKMT_GPU_PREFERENCE_STATE_HIGH_PERFORMANCE
* D3DKMT_GPU_PREFERENCE_STATE_MINIMUM_POWER
* D3DKMT_GPU_PREFERENCE_STATE_UNSPECIFIED