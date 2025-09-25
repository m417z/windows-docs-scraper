# _DXVAHDDDI_FILTER_RANGE_DATA structure

## Description

The **DXVAHDDDI_FILTER_RANGE_DATA** structure describes a filter range.

## Members

### `Minimum` [in]

An **INT** that specifies the minimum value in the filter range.

### `Maximum` [in]

An **INT** that specifies the maximum value in the filter range.

### `Default` [in]

An **INT** that specifies the default value for the filter range.

### `Multiplier` [in]

A **FLOAT** value that specifies a multiplier to calculate the actual filter value.

## Remarks

A hue ProcAmp filter that is defined from –180.0 to 180.0 at 0.25 step size with a default value of 0.0 has the members of the **DXVAHDDDI_FILTER_RANGE_DATA** structure set to the following values, which are normalized by an implicit step size of 1:

* **Minimum** = –720
* **Maximum** = 720
* **Default** = 0
* **Multiplier** = 0.25