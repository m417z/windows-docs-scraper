# WTSINFOEXW structure

## Description

Contains a [WTSINFOEX_LEVEL](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wtsinfoex_level_a) union that contains extended information about a Remote Desktop Services session. This structure is returned by the [WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa) function when you specify "WTSSessionInfoEx" for the *WTSInfoClass* parameter.

## Members

### `Level`

Specifies the level of information contained in the **Data** member. This can be the following value.

#### 1

The **Data** member is a [WTSINFOEX_LEVEL1](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wtsinfoex_level1_a) structure.

### `Data`

A [WTSINFOEX_LEVEL](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wtsinfoex_level_a) union. The type of structure contained here is specified by the **Level** member.

##### - Level.1

The **Data** member is a [WTSINFOEX_LEVEL1](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wtsinfoex_level1_a) structure.

## See also

[WTSINFOEX_LEVEL](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wtsinfoex_level_a)

[WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa)

## Remarks

> [!NOTE]
> The wtsapi32.h header defines WTSINFOEX as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).