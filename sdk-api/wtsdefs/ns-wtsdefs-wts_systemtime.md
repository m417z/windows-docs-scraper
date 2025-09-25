# WTS_SYSTEMTIME structure

## Description

Specifies date and time information for transitions between standard time and daylight saving time.

## Members

### `wYear`

The year from 1601 to 30827.

### `wMonth`

The month when transition from standard to daylight saving time occurs. This can be one of the following values.

#### 1

January

#### 2

February

#### 3

March

#### 4

April

#### 5

May

#### 6

June

#### 7

July

#### 8

August

#### 9

September

#### 10

October

#### 11

November

#### 12

December

### `wDayOfWeek`

The day of the week when the transition occurs. This can be one of the following values.

#### 0

Sunday

#### 1

Monday

#### 2

Tuesday

#### 3

Wednesday

#### 4

Thursday

#### 5

Friday

#### 6

Saturday

### `wDay`

The day of the month when the transition occurs.

### `wHour`

The hour when the transition occurs.

### `wMinute`

The minute when the transition occurs.

### `wSecond`

The second when the transition occurs.

### `wMilliseconds`

The millisecond when the transition occurs.