typedef struct _MI_PropertySetFT {
  MI_Result((const MI_PropertySet *self,MI_Uint32 *count) * )GetElementCount;
  MI_Result(const MI_PropertySet *self, const MI_Char *name,MI_Boolean *flag) * )(ContainsElement;
  MI_Result((MI_PropertySet *self, const MI_Char *name) * )AddElement;
  MI_Result(const MI_PropertySet *self,MI_Uint32 index, const MI_Char **name) * )(GetElementAt;
  MI_Result()(MI_PropertySet *self) * Clear;
  MI_Result()(MI_PropertySet *self) * Destruct;
  MI_Result()(MI_PropertySet *self) * Delete;
  MI_Result(const MI_PropertySet *self,MI_PropertySet **newPropertySet) * )(Clone;
} MI_PropertySetFT;