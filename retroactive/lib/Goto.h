Property external_name;

[ Refers obj wnum wd i;
  if (obj==0) rfalse;

  i = wn; wn = wnum; wd = NextWordStopped(); wn = i;

  if (WordInProperty(wd, obj, name)) rtrue;

  if (obj provides external_name) {
    if (WordInProperty(wd, obj, external_name)) rtrue;
  }

  if (parent(obj) == Compass) {
    i = location;
    
    if (i == thedark) {
      i = real_location;
    }
    
    i = LeadsTo(obj, i);

    if (i==0) rfalse;

    if (WordInProperty(wd, i, external_name)) rtrue;

    if (i has concealed) rfalse;

    if (i hasnt visited && i hasnt transparent) rfalse;

    if (WordInProperty(wd, i, name)) rtrue;
  }

  rfalse;
];

[ LeadsTo direction thisroom k tmp tmp2;
  if (~~(direction provides door_dir)) rfalse;
  if (~~(thisroom provides direction.door_dir)) rfalse;

  k=thisroom.(direction.door_dir);

  if (ZRegion(k) == 2) {
    k = k();
  }

  if (ZRegion(k)~=1) rfalse;

  if (k has door) {
    tmp = parent(k);
    move k to thisroom;
    tmp2 = k.door_to();

    if (tmp == 0) {
      remove k;
    } else {
      move k to tmp;
    }

    k = tmp2;
  }

  return k;
];
