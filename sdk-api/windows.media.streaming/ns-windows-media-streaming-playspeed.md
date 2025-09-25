# PlaySpeed structure

## Description

Represents a playback speed as a rational number.

## Members

### `streaming.PlaySpeed.Numerator`

### `streaming.PlaySpeed.Denominator`

### `Denominator`

The **Numerator** should be divided by this value to obtain the play speed. A value of 0 is not allowed.

### `Numerator`

A value that when divided by the **Denominator** represents the play speed.

## Remarks

The **Numerator** is a signed integer, allowing for negative speeds. A negative speed means that the content is played in reverse. A speed of 1 means that the content is played at its normal playback speed.