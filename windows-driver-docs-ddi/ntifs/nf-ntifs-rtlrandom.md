# RtlRandom function

## Description

The **RtlRandom** routine returns a random number that was generated from a given seed value.

## Parameters

### `Seed` [in, out]

Unsigned long value from which to generate a random number.

## Return value

**RtlRandom** returns a random number in the range [0..MAXLONG-1].

## Remarks

**RtlRandom** returns values that are uniformly distributed over the range from zero to the maximum possible LONG value less 1 if it is called repeatedly with the same *Seed*.

The **RtlRandomEx** function is an improved version of the **RtlRandom** function that is twice as fast and produces better random numbers.

## See also

[RtlRandomEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlrandomex)