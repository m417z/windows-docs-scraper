typedef enum LineCap {
  LineCapFlat = 0,
  LineCapSquare = 1,
  LineCapRound = 2,
  LineCapTriangle = 3,
  LineCapNoAnchor = 0x10,
  LineCapSquareAnchor = 0x11,
  LineCapRoundAnchor = 0x12,
  LineCapDiamondAnchor = 0x13,
  LineCapArrowAnchor = 0x14,
  LineCapCustom = 0xff,
  LineCapAnchorMask = 0xf0
} ;