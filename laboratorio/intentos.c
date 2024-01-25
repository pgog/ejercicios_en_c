 /* if (registro_año != matriculas[i].año || id != matriculas[i].ID_estudiante || semestre != matriculas[i].semestre)
            {
                for (int j = 0; j < numero_estudiantes ; j++)
                {
                    if (matriculas[i].ID_estudiante == estudiantes[j].ID_estudiante)
                    {
                        if (estudiantes[j].bandera2 == 0)
                        {
                            mu_acum++;
                            break;
                        }
                        else if (estudiantes[j].bandera2 == 1)
                        {
                            mg_acum++;
                            break;
                        }
                        else if (estudiantes[j].bandera2 == 2)
                        {
                            fu_acum++;
                            break;
                        }
                        else if (estudiantes[j].bandera2 == 3)
                        {
                            fg_acum++;
                            break;
                        }
                    }
                }
                registro_año = matriculas[i].año;
                id = matriculas[i].ID_estudiante;
                semestre = matriculas[i].semestre;
                printf("%-10d %-15d %-15d %-15d %-15d %d\n", registro_año, semestre, mu_acum, fu_acum, mg_acum, fg_acum);
            } */
        }

        /* for (int i = 0; i < numero_estudiantes; i++)
        {

            for (int j = 0; j < numero_matriculas; j++)
            {
                if (estudiantes[i].ID_estudiante == matriculas[j].ID_estudiante)
                {
                    for (int k = 0; k < numero_matriculas; k++)
                    {
                        if (registro_año == matriculas[k].año)
                        {
                            for (int l = 1; l < 5; l++)
                            {
                                if (matriculas[k].semestre == l)
                                {
                                    if (estudiantes[i].bandera2 == 0)
                                    {
                                        mu_acum++;
                                    }
                                    else if (estudiantes[i].bandera2 == 1)
                                    {
                                        mg_acum++;
                                    }
                                    else if (estudiantes[i].bandera2 == 2)
                                    {
                                        fu_acum++;
                                    }
                                    else if (estudiantes[i].bandera2 == 3)
                                    {
                                        fg_acum++;
                                    }

                                }
                            }
                        }
                        else
                        {
                            registro_año == matriculas[i].año;
                        }
                    }
                }
            }
        } */