typedef volatile unsigned long vuint32_t;

typedef union FCCU_CTRL_union_tag {    /* Control */
  vuint32_t R;
  struct {
    vuint32_t FILTER_BYPASS:1;
    vuint32_t FILTER_WIDTH:2;
    vuint32_t  :19;
    vuint32_t DEBUG:1;                 /* Debug Mode Enable */
    vuint32_t  :1;
    vuint32_t OPS:2;
    vuint32_t  :1;
    vuint32_t OPR:5;
  } B;
} FCCU_CTRL_tag;

struct FCCU_tag {
  FCCU_CTRL_tag CTRL;                  /* Control */
  FCCU_CTRLK_tag CTRLK;                /* Control Key */
};
#define FCCU (*(volatile struct FCCU_tag *) 0xFBF58000UL)