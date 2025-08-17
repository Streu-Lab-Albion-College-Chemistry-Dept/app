#include "../profiles/profiles.h"
#include "./components.h"
#include "../tabs/tabs.h"
#include <stdlib.h>

/*
 * Top Menu Bar
*/
void RenderHeaderButton(Clay_String text, AppContext* ctx) {
  CLAY({
    .layout = {
      .padding = CLAY_PADDING_ALL(8),
      .childAlignment = {.y = CLAY_ALIGN_Y_CENTER},
    },
    .cornerRadius = CLAY_CORNER_RADIUS(4),
    .backgroundColor = {165, 205, 125, 255},
  }) {
    CLAY_TEXT(text, CLAY_TEXT_CONFIG({
      .fontSize = 16,
      .textColor = {255, 255, 255, 255},
    }));
  }
}

void RenderHeaderDropdownButton(Clay_String text, AppContext* ctx) {
  CLAY({
    .id = CLAY_ID("file-menu-button"),
    .layout = {
      .padding = CLAY_PADDING_ALL(8),
      .sizing = {.width = CLAY_SIZING_GROW(0)}
    },
    .cornerRadius = CLAY_CORNER_RADIUS(4),
    .backgroundColor = {140, 140, 140, 255},
  }) {
    CLAY_TEXT(text, CLAY_TEXT_CONFIG({
      .fontSize = 16,
      .textColor = {255, 255, 255, 255},
    }));
  }
}

void SideBar(AppContext* ctx) {
  Clay_Sizing expandLayout = {
    .height = CLAY_SIZING_GROW(0),
    .width  = CLAY_SIZING_GROW(0),
  };
  
  CLAY({ 
    .id = CLAY_ID("SideBar"),
    .layout = {
      .layoutDirection = CLAY_TOP_TO_BOTTOM,
      .childGap        = 16,
      .padding         = CLAY_PADDING_ALL(8),
      .sizing = {
        .width  = CLAY_SIZING_FIXED(250),
        .height = CLAY_SIZING_GROW(0),
      }
    },
    .backgroundColor = {105, 48, 140, 255},
    .cornerRadius = CLAY_CORNER_RADIUS(12)
  }) {
    CLAY({
      .cornerRadius = CLAY_CORNER_RADIUS(8),
      .backgroundColor = {23, 45, 56, 200},
      .id = CLAY_ID("info-bar"),
      .layout = {
        .layoutDirection = CLAY_TOP_TO_BOTTOM,
        .padding = CLAY_PADDING_ALL(8),
        .sizing = {
          .height = CLAY_SIZING_FIXED(242),
          .width  = CLAY_SIZING_GROW(0),
        }
      },
    }) {
      UserProfileWidget(ctx);
    }
    
    CLAY({
      .id = CLAY_ID("exp-configs"),
      .cornerRadius = CLAY_CORNER_RADIUS(8),
      .backgroundColor = {13, 34, 23, 150},
      .layout = {
        .sizing  = expandLayout,
        .layoutDirection = CLAY_TOP_TO_BOTTOM,
        .childGap = 16,
        .padding = CLAY_PADDING_ALL(8),
      },
    }) {
      RenderHeaderButton(CLAY_STRING("Dr Streu San"), ctx);
      CLAY_TEXT(CLAY_STRING("PI"), CLAY_TEXT_CONFIG({
        .fontSize = 16,
        .textColor = {255, 255, 255, 255},
      }));
    }
  };
}

void Tabs(Clay_String title) {
  CLAY({
    .backgroundColor = {123, 234, 144, 178},
    .cornerRadius = CLAY_CORNER_RADIUS(4),
    .layout = {
      .padding = {16, 16, 12, 12},
      .sizing = {.width = CLAY_SIZING_FIXED(80)}
    },
  }) {
    CLAY_TEXT(title, CLAY_TEXT_CONFIG({
      .fontSize  = 16,
      .textColor = {255, 255, 255, 255}
    }));
  }
}

void TopMenuBar(AppContext* ctx) {
  CLAY({
    .backgroundColor = {130, 35, 180, 255},
    .cornerRadius = {12, 12, 12, 12},
    .id = CLAY_ID("top-menu-bar"),
    .layout = {
      .layoutDirection = CLAY_LEFT_TO_RIGHT,
      .padding = {8, 8, 8, 8},
      .sizing = {
        .width  = CLAY_SIZING_GROW(0),
      },
      .childGap = 16,
      .childAlignment = {.y = CLAY_ALIGN_Y_CENTER},
    },
  }) {
    CLAY({
      .id = CLAY_ID("file-button"),
      .layout = {
        .padding = {8, 8, 8, 8},
      },
      .backgroundColor = {140, 140, 140, 255},
      .cornerRadius = {4, 4, 4, 4},
    }) {
      CLAY_TEXT(CLAY_STRING("File"), CLAY_TEXT_CONFIG({
          .fontSize = 16,
          .textColor = {255, 255, 255, 255},
      }));

      bool fileMenuVisible = 
        Clay_PointerOver(Clay_GetElementId(CLAY_STRING("file-menu")))
        ||
        Clay_PointerOver(Clay_GetElementId(CLAY_STRING("file-button")));

      if (fileMenuVisible) {
         CLAY({
          .id = CLAY_ID("file-menu"),
          .floating = {
            // .offset = {.y = 8},
            .attachTo = CLAY_ATTACH_TO_PARENT,
            .attachPoints = {
              .parent = CLAY_ATTACH_POINT_LEFT_BOTTOM,
            }
          },
          .cornerRadius = {8, 8, 8, 8},
          .backgroundColor = {40, 40, 40, 255},
          .layout = {
            .padding = {0, 0, 8, 8},
            .layoutDirection = CLAY_TOP_TO_BOTTOM,
            .padding = {10, 10, 10, 10},
            .childGap = 8,
            .sizing = {.width = CLAY_SIZING_FIXED(200)} 
          },
        }) {
          RenderHeaderDropdownButton(CLAY_STRING("New"), ctx);
          RenderHeaderDropdownButton(CLAY_STRING("Open"), ctx);
          RenderHeaderDropdownButton(CLAY_STRING("Save"), ctx);
          RenderHeaderDropdownButton(CLAY_STRING("Close"), ctx);
        }
      }
    }
    
    CLAY({.layout = {.sizing = {.width = CLAY_SIZING_GROW()}}}) {};
    RenderHeaderButton(CLAY_STRING("File"), ctx);
    RenderHeaderButton(CLAY_STRING("Edit"), ctx);
    RenderHeaderButton(CLAY_STRING("Settings"), ctx);
  }
}

static TabPropsArray tabsList = (TabPropsArray) {
  .length = 2,
  .selectedIndex = 0,
  .props = (TabProps[]) {
    {.title = CLAY_STRING("Main"), .contentView = ContextTabs},
    {.title = CLAY_STRING("Exps"), .contentView = DemoView},
  },
};

static TabsInterface interface[MAX_TABS];

void MainContent(AppContext* ctx) {
  CLAY({
    .id = CLAY_ID("main-content"),
    .clip = {.vertical = true, .childOffset = Clay_GetScrollOffset()},
    .cornerRadius = {12, 12, 12, 12},
    .backgroundColor = {130, 145, 34, 200},
    .layout = {
      .childGap = 8,
      .layoutDirection = CLAY_TOP_TO_BOTTOM,
      .padding = {8, 8, 8, 8},
      .sizing = {
        .width  = CLAY_SIZING_GROW(0),
        .height = CLAY_SIZING_GROW(0),
      },
    }
  }) {

    CLAY({
      .layout = {
        .layoutDirection = CLAY_LEFT_TO_RIGHT,
        .childGap = 8,
      }
    })  {
      for (uint8_t i = 0; i < tabsList.length; ++i) { 
        interface[i].currentIndex = i;
        interface[i].tabsList = &tabsList;
        
        bool isSelected = (i == tabsList.selectedIndex);

        CLAY({
          .id = CLAY_IDI("tabs", i),
          .backgroundColor = isSelected 
            ? (Clay_Color) {123, 223, 234, 100}
            : (Clay_Color) {233, 100, 76, 200},
        }) { 
          Clay_OnHover(HandleTabClick, (intptr_t)&interface[i]);
          Tabs(tabsList.props[i].title); 
        }
      }
    }
    
    TabProps view = tabsList.props[tabsList.selectedIndex];
    view.contentView(ctx);
  }
}

void Terminal(AppContext* ctx) {
  CLAY({
    .layout = {
      .sizing = {
        .width = CLAY_SIZING_GROW(0),
        .height = CLAY_SIZING_FIXED(80),
      },
      .childGap = 16,
    },
    .backgroundColor = {140, 123, 109, 111},
    .cornerRadius = {8, 8, 8, 8}
  }) {}
}
