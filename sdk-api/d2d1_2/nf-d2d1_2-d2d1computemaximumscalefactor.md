# D2D1ComputeMaximumScaleFactor function

## Description

Computes the maximum factor by which a given transform can stretch any vector.

## Parameters

### `matrix` [in]

The input transform matrix.

## Return value

The scale factor.

## Remarks

Formally, if M is the input matrix, this method will return the maximum value of |V * M| / |V| for all vectors V, where |.| denotes length.

**Note** Since this describes how M affects vectors (rather than points), the translation components (_31 and _32) of M are ignored.