# TS_RUNINFO structure

## Description

The **TS_RUNINFO** structure specifies the properties of text run data.

## Members

### `uCount`

Specifies the number of characters in the text run.

### `type`

Specifies the text run type. If this parameter is TS_RT_PLAIN, the text run is visible. If this parameter is TS_RT_HIDDEN, the text run is hidden. If this parameter is TS_RT_OPAQUE, the text run is a private data type embedded in the text by application or text service that implements the ITextStore interface.

## Remarks

A text run is a collection of consecutive visible, hidden, or embedded characters. For example, the text, Hello World in HTML might be <b>Hello </b><i>World</i>. This text is represented in the TS_RUNINFO structure as follows.

| Text Run | uCount | TsRunType |
| --- | --- | --- |
| <b> | 3 | TS_RT_HIDDEN |
| Hello<space> | 5 | TS_RT_PLAIN |
| </b><i> | 7 | TS_RT_HIDDEN |
| World | 5 | TS_RT_PLAIN |
| </i> | 4 | TS_RT_HIDDEN |