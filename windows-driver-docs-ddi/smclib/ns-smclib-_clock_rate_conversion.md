# _CLOCK_RATE_CONVERSION structure

## Description

The CLOCK_RATE_CONVERSION structure holds a value that determines the duration of a bit of data and the corresponding maximum operating frequency that accompanies the indicated bit length.

## Members

### `F`

Contains a value that calculates the elementary time unit (ETU). The ETU indicates the space of transmission time that is occupied by a single bit of data. For more information, see the *ISO 7816-3 Specification*.

### `fs`

Contains the maximum clock frequency that is allowed. For more information, see the *ISO 7816-3 Specification*.

## Remarks

As stated in the *ISO 7816-3 Specification*, the operating system defines an array of CLOCK_RATE_CONVERSION structures that determine the maximum operating frequency for a smart card or a smart card reader. The *ISO 7816-3 Specification* defines a mapping between ETUs and clock frequencies. The following array, defined in *Smclib.h*, shows the mapping:

```
static CLOCK_RATE_CONVERSION ClockRateConversion[] = {
  { 372, 4 MHZ },
  { 372, 5 MHZ },
  { 558, 6 MHZ },
  { 744, 8 MHZ },
  { 1116, 12 MHZ },
  { 1488, 16 MHZ },
  { 1860, 20 MHZ },
  { 0, 0 },
  { 0, 0 },
  { 512, 5 MHZ },
  { 768, 7500000 },
  { 1024, 10 MHZ },
  { 1536, 15 MHZ },
  { 2048, 20 MHZ },
  { 0, 0 },
  { 0, 0 }
};
```