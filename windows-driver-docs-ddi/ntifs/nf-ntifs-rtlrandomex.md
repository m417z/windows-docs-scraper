# RtlRandomEx function

## Description

The **RtlRandomEx** routine returns a random number that was generated from a given seed value.

## Parameters

### `Seed` [in, out]

Unsigned long value from which to generate a random number.

## Return value

**RtlRandomEx** returns a random number in the range [0..MAXLONG-1].

## Remarks

**RtlRandomEx** returns values that are uniformly distributed over the range from zero to the maximum possible LONG value less 1 if it is called repeatedly with the same *Seed*.

The **RtlRandomEx** function is an improved version of the **RtlRandom** function. Compared with the **RtlRandom** function, **RtlRandomEx** is twice as fast and produces better random numbers since the period of the random numbers generated is comparatively higher.

## See also

[RtlRandom](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlrandom)