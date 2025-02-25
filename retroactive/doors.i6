[ IsAWordIn w obj prop k l m;
  k = obj.&prop; l = (obj.#prop) / 2;

  for (m = 0 : m < l : m++)
    if (w == k --> m) rtrue;
  
  rfalse;
];

Class DirDoor
with
  parse_name [ n word;
    word = NextWordStopped();

    while (word ~= -1) {
      if (IsAWordIn(word, self, name) == 1) n++;
      if (location == self.s_to && (word == 'north' or 'northern')) n++;
      if (location == self.n_to && (word == 'south' or 'southern')) n++;
      if (location == self.e_to && (word == 'west' or 'western')) n++;
      if (location == self.w_to && (word == 'east' or 'eastern')) n++;
      if (location == self.se_to && (word == 'northwest' or 'northeastern')) n++;
      if (location == self.sw_to && (word == 'northeast' or 'northeastern')) n++;
      if (location == self.ne_to && (word == 'southwest' or 'southwestern')) n++;
      if (location == self.nw_to && (word == 'southeast' or 'southeastern')) n++;
      word = NextWordStopped();
    }

    return n;
  ]
;

Class Connector class DirDoor
has door static
with
  sidea 0,
  sideb 0,
  dira 0,
  dirb 0,

  found_in 0 0,

  door_dir [;
    if (location == self.sidea) return self.dira; return self.dirb;
  ],

  door_to [;
    if (location == self.sidea) return self.sideb; return self.sidea;
  ]
;

[ InitDoors j o i;
  objectloop (j ofclass Connector) {
    ! print (object) j, "^";

    objectloop (o in compass) {
      ! print (object) o, "^";

      i = o.door_dir;

      if (j provides i) {
        ! print (object) j, " provides ", i, " for ", (object) o, ".^";

        j.sidea = j.i;
        j.dirb = i;
      }
    };

    objectloop (o in compass) {
      i = o.door_dir;

      if ((j provides i) && (j.dirb ~= i)) {
        j.sideb = j.i;
        j.dira = i;
      }
    };

    j.&found_in --> 0 = j.sidea;
    j.&found_in --> 1 = j.sideb;
  };
];
