typedef enum TreeScope {
  TreeScope_None = 0x0,
  TreeScope_Element = 0x1,
  TreeScope_Children = 0x2,
  TreeScope_Descendants = 0x4,
  TreeScope_Parent = 0x8,
  TreeScope_Ancestors = 0x10,
  TreeScope_Subtree
} ;