# TsRunType enumeration

## Description

Elements of the **TsRunType** enumeration specify if a text run is visible, hidden, or is a private data type embedded in the text run.

## Constants

### `TS_RT_PLAIN:0`

The text run is visible.

### `TS_RT_HIDDEN`

The text run is hidden.

### `TS_RT_OPAQUE`

The text run is a private data type embedded in the text run.

## Remarks

A text run is a collection of consecutive characters that is visible, hidden, or contains embedded data. For example, the text, Hello World in HTML might be <b>Hello </b><i>World</i>. This text would be defined using the TsRunType as in the following.

| Text Run | Value |
| --- | --- |
| <b> | TS_RT_HIDDEN |
| Hello\<space> | TS_RT_PLAIN |
| </b> | TS_RT_HIDDEN |
| <i> | TS_RT_HIDDEN |
| World | TS_RT_PLAIN |
| </i> | TS_RT_HIDDEN |

## See also

[ITextStoreACP::GetText](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-gettext)

[TS_RUNINFO](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_runinfo)